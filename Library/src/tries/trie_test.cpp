#include "gtest/gtest.h"
#include "trie.h"

TEST(TrieTest, BasicTest) {
	Trie<char, std::string> dictionary('\0');
	dictionary.insert("karma", "Destiny or fate, following as effect from cause");
	Trie<char, std::string>::Iterator iter = dictionary.startsWith("kar");
	for (; iter != dictionary.end(); ++iter) {
		std::cout << iter->first << " : " << iter->second->c_str() << std::endl;
	}
}
