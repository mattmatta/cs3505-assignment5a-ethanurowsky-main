#ifndef TRIE_H
#define TRIE_H

#include <iostream>
#include <vector>
#include <string>
#include <map>

/*
Header file for a trie class using std::map for storage.
This class represents a Trie data structure.
By: Ethan Urowsky and Matthew Mattamana
Refactored on 02/18/2025
*/

class Trie {
private:
    std::map<char, Trie> branches;  // Map storing character -> Trie
    bool isEndOfWord;  // Flag to determine if node represents a word end.

    /// @brief Helper function to get words with given prefix recursively.
    /// @param prefix - The prefix to search for.
    /// @param results - Vector with words found that begin with the specified prefix.
    void collectWords(const std::string& prefix, std::vector<std::string>& results) const;

public:
    /// @brief Default constructor
    Trie();

    /// @brief Destructor
    ~Trie() = default;  // No dynamic allocation, default destructor is fine.

    /// @brief Copy constructor
    Trie(const Trie& other);

    /// @brief Assignment operator
    Trie& operator=(const Trie& other);

    /// @brief Adds a word into the Trie.
    /// @param word - Word to be added.
    void addWord(const std::string& word);

    /// @brief Checks if a given word exists in the Trie.
    /// @param word - Word to check.
    /// @return True if word is found, false otherwise.
    bool isWord(const std::string& word) const;

    /// @brief Gets words in the Trie that begin with a specified prefix.
    /// @param prefix - The prefix to search for.
    /// @return Vector of words found that start with the given prefix.
    std::vector<std::string> allWordsStartingWithPrefix(const std::string& prefix) const;
};

#endif  // TRIE_H
