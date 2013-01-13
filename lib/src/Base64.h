#ifndef BASE64_H_
#define BASE64_H_

#include <string>
#include <iostream>

class Base64 {
public:
	// TODO: Input can be binary data, so std::string might not be best choice..
	static std::string encode(std::string input);
	static std::string decode(std::string input);

	// TODO: Implement with streams support.
	// static void encode(std::istream& istream_in, std::ostream& ostream_in);
	// static void decode(std::istream& istream_in, std::ostream& ostream_in);
private:
	static std::string ENCODING_MAP;
};

#endif /* BASE64_H_ */
