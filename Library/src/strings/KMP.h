#ifndef KMP_H_
#define KMP_H_

#include <vector>
#include <string>

/**
 * @see http://community.topcoder.com/tc?module=Static&d1=tutorials&d2=stringSearching
 */
template<class CharType>
class KMP {
public:
	/**
	 * Generates the failure function of the given pattern.
	 * Index in the result is the number of characters of the pattern already matched.
	 * Value represents the next partial match, if the matching fails at next character in the pattern.
	 */
	static std::vector<size_t> BuildFailureFunction(std::basic_string<CharType> pattern) {
		// No. of prefixes for string of length n = n + 1 (including empty string)
		std::vector<size_t> F(pattern.size() + 1, 0);
		for (size_t i = 2; i <= pattern.size(); i++) {
			size_t pos = F[i - 1];

			for (;;) {
				// check to see if the last character of string i - pattern[i - 1] "expands" the current "candidate"
				// best partial match - the prefix under index pos
				if (pattern[pos] == pattern[i - 1]) {
					F[i] = pos + 1;
					break;
				}

				// if we cannot "expand" even the empty string
				if (pos == 0) {
					F[i] = 0;
					break;
				}
				// else go to the next best "candidate" partial match
				pos = F[pos];
			}
		}
		return F;
	}

	// Returns the indices of all the matches of pattern in text (might include overlap)
	static std::vector<size_t> all(std::basic_string<CharType> text,
			std::basic_string<CharType> pattern) {
		return _findMatches(text, pattern, false);
	}

	// Return the index of 1st match or std::basic_string:npos if no match is found.
	static size_t match(std::basic_string<CharType> text, std::basic_string<CharType> pattern) {
		std::vector<size_t> matches = _findMatches(text, pattern, true);
		return matches.size() > 0 ? matches[0] : std::basic_string<CharType>::npos;
	}
private:

	/** Returns the indices of all the matches of pattern in text (might include overlap), or only 1st one if specified.*/
	static std::vector<size_t> _findMatches(std::basic_string<CharType> text,
			std::basic_string<CharType> pattern, bool firstOnly = false) {
		std::vector<size_t> matches;
		std::vector<size_t> F = BuildFailureFunction(pattern);
		size_t i = 0; // index in text
		size_t j = 0; // index in pattern, which means j characters are already matched.
		while (i < text.size()) {
			if (text[i] == pattern[j]) {
				i++;
				j++;
				if (j == pattern.size()) { // match found
					matches.push_back(i - j);
					if (firstOnly) {
						return matches;
					}
					// To get overlapping matches
					j = F[j];
				}
			} else if (j > 0) {
				j = F[j];
			} else { // Reached empty string, failed to expand.
				i++;
			}
		}
		return matches;
	}
};

#endif /* KMP_H_ */
