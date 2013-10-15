#include "gtest/gtest.h"
#include "KMP.h"

TEST(KMPTest, BuildFailureFunction) {
	{
		// Example data from http://community.topcoder.com/tc?module=Static&d1=tutorials&d2=stringSearching
		std::vector<size_t> F = KMP<char>::BuildFailureFunction("ABABAC");
		ASSERT_EQ(7, F.size());
		size_t expected[] = { 0, 0, 0, 1, 2, 3, 0 };
		for (size_t i = 0; i < F.size(); i++) {
			EXPECT_EQ(expected[i], F[i]) << "Result and expected differ at index:" << i;
		}
	}
	{
		std::vector<size_t> F = KMP<char>::BuildFailureFunction("ABAB");
		ASSERT_EQ(5, F.size());
		size_t expected[] = { 0, 0, 0, 1, 2 };
		for (size_t i = 0; i < F.size(); i++) {
			EXPECT_EQ(expected[i], F[i]) << "Result and expected differ at index:" << i;
		}
	}
}

TEST(KMPTest, TestAllMatches) {
	{
		std::vector<size_t> matches = KMP<char>::all("AAAA", "AA");
		size_t expected[] = { 0, 1, 2 };
		ASSERT_EQ(3, matches.size());
		for (size_t i = 0; i < matches.size(); i++) {
			EXPECT_EQ(expected[i], matches[i]) << "Result and expected differ at index:" << i;
		}
	}
	{
		std::vector<size_t> matches = KMP<char>::all("DABABABC", "ABAB");
		size_t expected[] = { 1, 3 };
		ASSERT_EQ(2, matches.size());
		for (size_t i = 0; i < matches.size(); i++) {
			EXPECT_EQ(expected[i], matches[i]) << "Result and expected differ at index:" << i;
		}
	}
}

TEST(KMPTest, TestSingleMatch) {
	ASSERT_EQ(0, KMP<char>::match("saiprasad", "sai"));
	ASSERT_EQ(0, KMP<char>::match("saiprasad", "saiprasad"));
	ASSERT_EQ(6, KMP<char>::match("saiprasad", "sad"));
	ASSERT_EQ(2, KMP<char>::match("acabab", "ab"));
	ASSERT_EQ(std::string::npos, KMP<char>::match("saiprasad", "qwerty"));
}
