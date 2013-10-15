#include "SuperFastHash.h"
#include "gtest/gtest.h"
#include <string>

TEST(SuperFastHashTest, ExampleUsage) {
	SuperFastHash hash;
	std::string str("saiprasad");
	ASSERT_EQ(2150875508, hash(str.c_str(), str.size()));
}
