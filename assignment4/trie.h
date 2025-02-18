#ifndef TRIE_H
#define TRIE_H

#include <iostream>
#include <vector>
#include <string>

/*
Header file for a trie class. 
This class represents the trie data structure. 
By: Ethan Urowsky
**02/06/2025**
*/

class Trie {
private:
    Trie* branches[26]; // C style array for each letter a-z.
    bool isEndOfWord; // flag to determine if node is end of a word.
    
    /// @brief Recursively deletes nodes and resets pointers to null.
    void clear();
    
    /// @brief Helper function to get words with given prefix using recursion.
    /// @param prefix - The prefix to search the words for.
    /// @param results - Vector with words found that begin with the specified prefix.
    void collectWords(std::string prefix, std::vector<std::string>& results) const;

public:

    /// @brief Default constructor
    Trie();

    /// @brief Destructor
    ~Trie();

    /// @brief Copy constructor
    /// @param other - other binary trie to copy.
    Trie(const Trie& other);

    /// @brief Assignment operator
    /// @param other - other binary trie to copy. 
    /// @return - reference to updated trie.
    Trie& operator=(Trie other);
    
    /// @brief Adds a word into the trie.
    /// @param word - Word to be added to trie.
    void addWord(const std::string& word);

    /// @brief Checks if the given word exists in the trie.
    /// @param word - Word to be checked.
    /// @return - True if word found, false if not.
    bool isWord(const std::string& word) const;

    /// @brief Gets words in the trie that begin with a specified prefix.
    /// @param prefix - The prefix to search the words for.
    /// @param results - Vector with words found that begin with the specified prefix.
    std::vector<std::string> allWordsStartingWithPrefix(const std::string& prefix) const;
};

#endif
