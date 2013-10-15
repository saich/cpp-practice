#include "PrintUtil.h"

std::string PrintUtil::bytes_to_hex(const char* data, size_t len)
{
	std::string hexstr = "";
	static const char hexes[] = "0123456789ABCDEF";

	for (size_t i = 0; i < len; i++) {
		unsigned char c = data[i];
		hexstr.push_back(hexes[c >> 4]);
		hexstr.push_back(hexes[c & 0xf]);
		hexstr.push_back(' '); // Delimit bytes with space.
	}
	return hexstr;
}

std::string PrintUtil::bytes_to_hex(const std::string& s)
{
	// @see http://stackoverflow.com/questions/194634/string-c-str-vs-data
	// data() returns the raw data, whereas c_str() is guaranteed to return
	// a NULL-terminated string, which may not be what we want.
	// Also, data() may turn out to perform better than c_str()
	return bytes_to_hex((const char *)s.data(), s.size());
}
