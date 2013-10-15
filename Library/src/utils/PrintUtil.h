#ifndef PRINTUTIL_H_
#define PRINTUTIL_H_

#include <string>

class PrintUtil {
public:
	static std::string bytes_to_hex(const char* data, size_t len);
	static std::string bytes_to_hex(const std::string& s);
private:
	PrintUtil();
};

#endif /* PRINTUTIL_H_ */
