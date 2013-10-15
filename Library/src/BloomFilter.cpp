#include "BloomFilter.h"
#include <tr1/random>

namespace {
// The Jenkins 96 bit mix function:
// http://www.concentric.net/~Ttwang/tech/inthash.htm
uint32_t HashMix(uint64_t hash_key, uint32_t c) {
  uint32_t a = static_cast<uint32_t>(hash_key)       & 0xFFFFFFFF;
  uint32_t b = static_cast<uint32_t>(hash_key >> 32) & 0xFFFFFFFF;

  a = a - b;  a = a - c;  a = a ^ (c >> 13);
  b = b - c;  b = b - a;  b = b ^ (a << 8);
  c = c - a;  c = c - b;  c = c ^ (b >> 13);
  a = a - b;  a = a - c;  a = a ^ (c >> 12);
  b = b - c;  b = b - a;  b = b ^ (a << 16);
  c = c - a;  c = c - b;  c = c ^ (b >> 5);
  a = a - b;  a = a - c;  a = a ^ (c >> 3);
  b = b - c;  b = b - a;  b = b ^ (a << 10);
  c = c - a;  c = c - b;  c = c ^ (b >> 15);

  return c;
}

} // namespace

BloomFilter::BloomFilter(size_t bit_size)
	: bit_size_(bit_size) {

	byte_size_ = bit_size_ / 8 + 1; // May end up 1 extra byte..
	data_.resize(byte_size_, 0);

	// TODO: Generate random hash_keys
	for (size_t i = 0; i < kNumHashKeys; ++i)
	    hash_keys_.push_back(123);
	std::tr1::mt19937 r;
}

// Notice that bytes are from left-to-right, whereas bits are taken from right-to-left..
// This is not a problem as long as they are same in insert and exists..
bool BloomFilter::exists(size_t hash) const {
	for (size_t i= 0; i < hash_keys_.size(); i++) {
		uint32_t mix = HashMix(hash_keys_[i], hash);
		uint32_t index = mix % bit_size_;
		size_t byte = index / 8;
		size_t bit = index % 8;

		// check if the bit is set.
		if (!(data_.at(byte) & (1 << bit)))
			return false;
	}
	return true;
}

void BloomFilter::insert(size_t hash) {
	for (size_t i = 0; i < hash_keys_.size(); i++) {
		uint32_t mix = HashMix(hash_keys_[i], hash);
		uint32_t index = mix % bit_size_;
		size_t byte = index / 8;
		size_t bit = index % 8;

		// set the bit
		data_[byte] |= (1 << bit);
	}
}
