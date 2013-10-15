#ifndef SUPERFASTHASH_H_
#define SUPERFASTHASH_H_

#include <cstddef> // for NULL
#include <stdint.h> // for uint16_t

#if defined(_MSC_VER)
#define FORCE_INLINE    __forceinline
#else
#define FORCE_INLINE inline __attribute__((always_inline))
#endif

FORCE_INLINE uint16_t get16bits ( const void * p )
{
  return *(const uint16_t*)p;
}

// TODO: Check this: On the down side, it has funnels of 3 bits into 2,
// for example hex 01 00 00 00 00 00 00 00 and 00 00 20 00 01 00 00 00 both hash to 0xc754ae23.

/**
 * Designed by: Paul Hsieh
 * @see http://www.azillionmonkeys.com/qed/hash.html
 * @see https://code.google.com/p/smhasher/source/browse/trunk/SuperFastHash.cpp
 *
 * This is very fast, and can be used with strings / binary data.
 *
 * This implementation takes the input data at once, but should be very easy to make
 * this take incremental value. (simply, initialize hash to the previous value, instead of 0).
 */
class SuperFastHash {
public:
	inline uint32_t operator()(const char* data, size_t len) const {
		uint32_t hash = 0, tmp;
		int rem;

		  if (len <= 0 || data == NULL) return 0;

		  rem = len & 3;
		  len >>= 2;

		  /* Main loop */
		  for (;len > 0; len--) {
		    hash  += get16bits (data);
		    tmp    = (get16bits (data+2) << 11) ^ hash;
		    hash   = (hash << 16) ^ tmp;
		    data  += 2*sizeof (uint16_t);
		    hash  += hash >> 11;
		  }

		  /* Handle end cases */
		  switch (rem) {
		    case 3:     hash += get16bits (data);
		        hash ^= hash << 16;
		        hash ^= data[sizeof (uint16_t)] << 18;
		        hash += hash >> 11;
		        break;
		    case 2:     hash += get16bits (data);
		        hash ^= hash << 11;
		        hash += hash >> 17;
		        break;
		    case 1: hash += *data;
		        hash ^= hash << 10;
		        hash += hash >> 1;
		  }

		  /* Force "avalanching" of final 127 bits */
		  hash ^= hash << 3;
		  hash += hash >> 5;
		  hash ^= hash << 4;
		  hash += hash >> 17;
		  hash ^= hash << 25;
		  hash += hash >> 6;

		  return hash;
	}
};

#endif /* SUPERFASTHASH_H_ */
