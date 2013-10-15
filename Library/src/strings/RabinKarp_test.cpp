#include "gtest/gtest.h"
#include "RabinKarp.h"

TEST(RabinKarpTest, TestSingleMatch) {
	RabinKarp rk;
	ASSERT_EQ(0, rk.match("saiprasad", "sai"));
	ASSERT_EQ(0, rk.match("saiprasad", "saiprasad"));
	ASSERT_EQ(6, rk.match("saiprasad", "sad"));
	ASSERT_EQ(2, rk.match("acabab", "ab"));
	ASSERT_EQ(std::string::npos, rk.match("saiprasad", "qwerty"));
}

TEST(RabinKarpTest, TestAllMatches) {
	RabinKarp rk;
	{
		std::vector<size_t> matches = rk.all("AAAA", "AA");
		size_t expected[] = { 0, 1, 2 };
		ASSERT_EQ(3, matches.size());
		for (size_t i = 0; i < matches.size(); i++) {
			EXPECT_EQ(expected[i], matches[i]) << "Result and expected differ at index:" << i;
		}
	}
	{
		std::vector<size_t> matches = rk.all("DABABABC", "ABAB");
		size_t expected[] = { 1, 3 };
		ASSERT_EQ(2, matches.size());
		for (size_t i = 0; i < matches.size(); i++) {
			EXPECT_EQ(expected[i], matches[i]) << "Result and expected differ at index:" << i;
		}
	}
}
