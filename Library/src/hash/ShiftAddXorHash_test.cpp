#include "ShiftAddXorHash.h"
#include <gtest/gtest.h>
#include <string>

TEST(ShiftAddXorHashTest, ExampleUsage) {
	ShiftAddXorHash hash = ShiftAddXorHash();
	std::string str("saiprasad");
	ASSERT_EQ(4254595823, hash(str.c_str(), str.size()));
}
