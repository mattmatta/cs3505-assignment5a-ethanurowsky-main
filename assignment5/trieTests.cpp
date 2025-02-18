#include "trie.h"
#include <gtest/gtest.h>
#include <vector>
#include <string>

// Test fixture for Trie
class TrieTest : public ::testing::Test {
protected:
    Trie trie;
};

// Test adding and checking words in the Trie
TEST_F(TrieTest, AddAndCheckWord) {
    trie.addWord("ethan");
    trie.addWord("Nimrod");
    trie.addWord("Barnsley");
    
    EXPECT_TRUE(trie.isWord("ethan"));
    EXPECT_TRUE(trie.isWord("Nimrod"));
    EXPECT_TRUE(trie.isWord("Barnsley"));
    EXPECT_FALSE(trie.isWord("GoonamicTrio"));
}