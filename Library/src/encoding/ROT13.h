#ifndef ROT13_H_
#define ROT13_H_

#include <string>

class ROT13 {
public:
	template<typename CharType>
	static std::basic_string<CharType> convert(std::basic_string<CharType> in) {
		for (size_t i = 0; i < in.size(); ++i) {
			CharType ch = in.at(i);
			if (isalpha(ch)) {
				if (tolower(ch) - 'a' < 14) {
					in[i] = ch + 13;
				} else {
					in[i] = ch - 13;
				}
			}
		}
		return in;
	}
};

#endif /* ROT13_H_ */
