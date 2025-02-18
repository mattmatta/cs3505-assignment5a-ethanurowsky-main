#include "trie.h"

/*
This class represents the trie data structure. 
A specialized tree structure that can have good performance retrieving dictionary words.
By: Ethan Urowsky
**02/06/2025**
*/

/// @brief Constructor
Trie::Trie() : isEndOfWord(false) {
    for (int i = 0; i < 26; i++) {
        branches[i] = nullptr;
    }
}

//Rule-Of-Three:

/// @brief Destructor
Trie::~Trie() {
    clear();
}

/// @brief Recursively deletes nodes and resets pointers to null.
void Trie::clear() {
    for (int i = 0; i < 26; i++) {
        if (branches[i]) {
            delete branches[i];
            branches[i] = nullptr;
        }
    }
}

/// @brief - Copy constructor
/// @param other - other binary trie to copy.
Trie::Trie(const Trie& other) : isEndOfWord(other.isEndOfWord) {
    for (int i = 0; i < 26; i++) {
        if (other.branches[i]) {
            branches[i] = new Trie(*other.branches[i]);
        } else {
            branches[i] = nullptr;
        }
    }
}

/// @brief Assignment operator
/// @param other - other binary trie to copy. 
/// @return - reference to updated trie.
Trie& Trie::operator=(Trie other) {
    std::swap(isEndOfWord, other.isEndOfWord);
    std::swap(branches, other.branches);
    return *this;
}

/// @brief Adds a word into the trie.
/// @param word - Word to be added to trie.
void Trie::addWord(const std::string& word) {
    Trie* node = this;
    for (char letter : word) { 
        int index = letter - 'a';
        if (!node->branches[index]) {
            node->branches[index] = new Trie();
        }
        node = node->branches[index];
    }
    node->isEndOfWord = true;
}

/// @brief Checks if the given word exists in the trie.
/// @param word - Word to be checked.
/// @return - True if word found, false if not.
bool Trie::isWord(const std::string& word) const {
    const Trie* node = this;
    for (char letter : word) {
        int index = letter - 'a';
        if (!node->branches[index]) {
            return false;
        }
        node = node->branches[index];
    }
    return node->isEndOfWord;
}

/// @brief Helper function to get words with given prefix using recursion.
/// @param prefix - The prefix to search the words for.
/// @param results - Vector with words found that begin with the specified prefix.
void Trie::collectWords(std::string prefix, std::vector<std::string>& results) const {
    if (isEndOfWord) {
        results.push_back(prefix);
    }
    for (int i = 0; i < 26; i++) {
        if (branches[i]) {
            branches[i]->collectWords(prefix + char(i + 'a'), results);
        }
    }
}

/// @brief Gets words in the trie that begin with a specified prefix.
/// @param prefix - The prefix to search the words for.
/// @return results - Vector with words found that begin with the specified prefix.
std::vector<std::string> Trie::allWordsStartingWithPrefix(const std::string& prefix) const {
    std::vector<std::string> results;
    const Trie* node = this;
    for (char letter : prefix) {
        int index = letter - 'a';
        if (!node->branches[index]) {
            return results; // Return empty if prefix not found
        }
        node = node->branches[index];
    }
    node->collectWords(prefix, results);
    return results;
}
