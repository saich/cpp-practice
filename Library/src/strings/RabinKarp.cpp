#include "RabinKarp.h"

RabinKarp::RabinKarp(size_t modulus, size_t base) :
		B(base), M(modulus) {
}
size_t RabinKarp::match(std::string text, std::string pattern) {
	std::vector<size_t> matches = _findMatches(text, pattern, true);
	return matches.size() > 0 ? matches[0] : std::string::npos;
}
std::vector<size_t> RabinKarp::all(std::string text, std::string pattern) {
	return _findMatches(text, pattern, false);
}

size_t RabinKarp::getHashCode(char c) {
	return static_cast<size_t>(c);
}

// correctly calculates a mod b even if a < 0
int64_t RabinKarp::mod(int64_t a, int64_t b) {
	return (a % b + b) % b;
}

// calculates a ^ b % c
int32_t RabinKarp::moduloExponentiation(int32_t a, int32_t b, int32_t c) {
	int64_t x = 1, y = a;
	while (b > 0) {
		if (b % 2 == 1) {
			x = (x * y) % c;
		}
		y = (y * y) % c;
		b /= 2;
	}
	return x % c;
}

std::vector<size_t> RabinKarp::_findMatches(std::string text, std::string pattern, bool firstOnly) {
	size_t m = pattern.size();
	size_t n = text.size();
	std::vector<size_t> matches;

	if (m > n)
		return matches; // no match is possible

	int64_t hashPattern = 0; // hash value of the pattern
	int64_t hashSegment = 0; // hash value of the segment
	for (size_t i = 0; i < m; i++) {
		hashPattern = ((hashPattern * B) + getHashCode(pattern[i])) % M;
		hashSegment = ((hashSegment * B) + getHashCode(text[i])) % M;
	}

	if (hashSegment == hashPattern) {
		matches.push_back(0);
		if (firstOnly)
			return matches;
	}

	// pre-compute B ^ (m-1) % M
	size_t E = moduloExponentiation(B, m - 1, M);

	for (size_t i = m; i < n; i++) {
		// string to consider: [i-m + 1, m]
		hashSegment = mod(hashSegment - mod(E * text[i - m], M), M);
		hashSegment = mod(hashSegment * B, M);
		hashSegment = mod(hashSegment + getHashCode(text[i]), M);

		if (hashSegment == hashPattern) {
			matches.push_back(i - m + 1);
			if (firstOnly)
				return matches;
		}
	}
	return matches;
}

