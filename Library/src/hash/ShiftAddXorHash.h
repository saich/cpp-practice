#ifndef SHIFTADDXORHASH_H_
#define SHIFTADDXORHASH_H_

#include <cstddef> // for NULL
#include <stdint.h> // for uint16_t

/**
 * Source: "Performance in Practice of String Hashing Functions" by M.V. Ramakrishna & Justin Zobel.
 *
 * This gives a class of hash functions, more suitable for strings.
 * Slight modification of seed, L, R will give different hash functions.
 * Super fast - Only 5 operations per character, and each takes just 1 instruction on processor.
 */
class ShiftAddXorHash {
public:
	// L=5, R=2 works well for ASCII input
	ShiftAddXorHash(uint32_t seed = 0, uint32_t L = 5, uint32_t R = 2) :
			m_seed(seed), m_l(L), m_r(R) {
	}

	inline uint32_t operator()(const char* data, size_t len) const {
		uint32_t hash = m_seed;
		if (len == 0 || data == NULL)
			return 0;

		for (size_t i = 0; i < len; i++) {
			hash ^= (hash << m_l) + (hash >> m_r) + data[i];
		}
		return hash;
	}
private:
	uint32_t m_seed, m_l, m_r;
};

#endif /* SHIFTADDXORHASH_H_ */
