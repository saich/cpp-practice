#ifndef RABINKARP_H_
#define RABINKARP_H_

#include <string>
#include <vector>

/**
 * For unicode strings, in this implementation, the string needs to converted to UTF-8 and represented as std::string.
 * The modulus must be preferably chosen a prime (http://primes.utm.edu/lists/small/1000.txt).
 *
 * The current implementation has chance for false positives, since it just relies on hashes to match.
 * Ideally, if hashes are equal, the strings need to be compared character-by-character to correctly
 * identifying the substring.
 *
 * A double hash can be used to reduce the chance for false-positives, i.e; use two sets of (B, M)
 * and calculate two hashes and report match only when hashes match for both the (B, M) values.
 *
 * There are better algorithms for single substring search than Rabin-Karp. Rabin-Karp is more
 * useful to search multiple patterns (of same length) in a given text at a time and similar variants.
 *
 * Some other variants,
 * - 2D string matching.
 * - String searching in forward or backward directions.
 */
class RabinKarp {

public:
	RabinKarp(size_t modulus = 127, size_t base = 256);
	size_t match(std::string text, std::string pattern);
	std::vector<size_t> all(std::string text, std::string pattern);
private:
	size_t getHashCode(char c);

	// correctly calculates a mod b even if a < 0
	int64_t mod(int64_t a, int64_t b);

	// calculates a ^ b % c
	int32_t moduloExponentiation(int32_t a, int32_t b, int32_t c);

	std::vector<size_t> _findMatches(std::string text, std::string pattern, bool firstOnly);

	const size_t B; // input character size
	const size_t M; // modulo
};

#endif /* RABINKARP_H_ */
