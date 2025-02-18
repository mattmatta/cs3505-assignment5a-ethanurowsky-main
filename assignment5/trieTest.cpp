#include "trie.h"
#include <iostream>
#include <fstream>

/*
Test program that exercises the Trie. 
This test program performs two tasks:
Checks if names exist in the Trie, and Tests the Rule-of-Three methods.
By: Ethan Urowsky
**02/06/2025**
*/

int main(int argc, char* argv[]) {
    // check arguments
    if (argc != 3) {
        std::cerr << "Usage: " << argv[0] << " <words file> <queries file>\n";
        return 1;
    }

    Trie trie;  // create the Trie
    std::ifstream wordsFile(argv[1]);
    std::ifstream queriesFile(argv[2]);
    std::string word;

    // check if files open
    if (!wordsFile || !queriesFile) {
        std::cerr << "error with file(s).\n";
        return 1;
    }

    // add names from file to Trie
    while (wordsFile >> word) {
        trie.addWord(word);
    }

    //queries
    while (queriesFile >> word) {
        std::cout << "Checking " << word << ":\n";

        // Check if the name exists
        if (trie.isWord(word)) {
            std::cout << "Name found\n";
        } else {
            std::cout << "Name not found\n";
        }

        // get and output names that start with the prefix
        std::vector<std::string> wordsWithPrefix = trie.allWordsStartingWithPrefix(word);
        std::cout << "Names with prefix \"" << word << "\": ";
        for (const std::string& name : wordsWithPrefix) { 
            std::cout << name << " ";
        }
        std::cout << "\n";
    }

    //Testing the Rule-of-Three

    std::cout << "\n Testing copy constructor and assignment operator\n";

    //add names to firstTrie
    Trie firstTrie;
    firstTrie.addWord("ethan");
    firstTrie.addWord("myles");
    firstTrie.addWord("asher");

    // output names in firstTrie
    std::cout << "Names in firstTrie: ";
    for (const std::string& name : firstTrie.allWordsStartingWithPrefix("")) {
        std::cout << name << " ";
    }
    std::cout << "\n";

    //Copy Constructor
    Trie secondTrie(firstTrie);
    std::cout << "Names in secondTrie: ";
    for (const std::string& name : secondTrie.allWordsStartingWithPrefix("")) {
        std::cout << name << " ";
    }
    std::cout << "\n";

    //Modify secondTrie and check if firstTrie is unchanged
    secondTrie.addWord("ari");
    std::cout << "Names in secondTrie after adding 'ari': ";
    for (const std::string& name : secondTrie.allWordsStartingWithPrefix("")) {
        std::cout << name << " ";
    }
    std::cout << "\n";

    std::cout << "Names in firstTrie: ";
    for (const std::string& name : firstTrie.allWordsStartingWithPrefix("")) {
        std::cout << name << " ";
    }
    std::cout << "\n";

    //Assignment Operator
    Trie thirdTrie;
    thirdTrie = secondTrie;
    std::cout << "Names in thirdTrie: ";
    for (const std::string& name : thirdTrie.allWordsStartingWithPrefix("")) {
        std::cout << name << " ";
    }
    std::cout << "\n";

    //Modify thirdTrie and check if secondTrie is unchanged
    thirdTrie.addWord("george");
    std::cout << "Names in thirdTrie after adding 'george': ";
    for (const std::string& name : thirdTrie.allWordsStartingWithPrefix("")) {
        std::cout << name << " ";
    }
    std::cout << "\n";

    std::cout << "Names in secondTrie: ";
    for (const std::string& name : secondTrie.allWordsStartingWithPrefix("")) {
        std::cout << name << " ";
    }
    std::cout << "\n";

    return 0;
}
