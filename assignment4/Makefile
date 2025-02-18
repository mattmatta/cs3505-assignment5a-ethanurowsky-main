# Makefile for the Trie data stucture. 
# Compiles and runs the assignment4 project, such as trie.cpp/h and trieTest.cpp
# By: Ethan Urowsky
# 02/06/2025

#compiler and flags used.
CXX = g++
CXXFLAGS = -Wall -Wextra -std=c++11 -fsanitize=address

# Targets
all: trieTest

trieTest: trie.o trieTest.o
	$(CXX) $(CXXFLAGS) -o trieTest trie.o trieTest.o

trie.o: trie.cpp trie.h
	$(CXX) $(CXXFLAGS) -c trie.cpp

trieTest.o: trieTest.cpp trie.h
	$(CXX) $(CXXFLAGS) -c trieTest.cpp

clean:
	rm -f trieTest *.o

test: trieTest
	./trieTest words.txt queries.txt
