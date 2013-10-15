#ifndef BLOOMFILTER_H_
#define BLOOMFILTER_H_

#include "utilities.h"
#include <vector>
class BloomFilter {
public:
	// constructs an empty filter with the given size
	explicit BloomFilter(size_t bit_size);

	~BloomFilter();

	size_t size() const {return byte_size_;}

	void insert(size_t hash);
	bool exists(size_t hash) const;
private:
	static const size_t kNumHashKeys = 20;
	std::vector<uint64_t> hash_keys_;
	size_t bit_size_;
	size_t byte_size_;

	std::vector<char> data_;
};

#endif /* BLOOMFILTER_H_ */
