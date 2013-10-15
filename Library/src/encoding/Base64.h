#ifndef BASE64_H_
#define BASE64_H_

#include <string>
#include <iostream>

class Base64 {
public:
	// TODO: Convert input parameter to std::vector<std::uint8_t> type to support binary input
	static std::string encode(std::string input);
	static std::string decode(std::string input);

	// TODO: Implement with streams support.
	// static void encode(std::istream& istream_in, std::ostream& ostream_in);
	// static void decode(std::istream& istream_in, std::ostream& ostream_in);
private:
	static std::string ENCODING_MAP;
};

#endif /* BASE64_H_ */
