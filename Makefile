CC = g++
CFLAGS = -Wall -std=c++11
GOOGLETEST ?= ./googletest/googletest

CURRDIR = .

all: Trie.o TrieTest.o TrieTest TrieTests

Trie.o : Trie.h Trie.cpp
	$(CC) $(CFLAGS) -g -c Trie.cpp

TrieTest.o : TrieTest.cpp Trie.o
	$(CC) $(CFLAGS) -g -c TrieTest.cpp Trie.o

TrieTest : Trie.o
	$(CC) $(CFLAGS) -g -o TrieTest TrieTest.o Trie.o

TrieTests: Trie.o
	$(CC) $(CFLAGS) -o TrieTests Trie.o TrieTests.cpp -L$(GOOGLETEST)/lib -I$(GOOGLETEST)/include -lgtest -lgtest_main -lpthread


clean:
	rm TrieTest *.o
	rm *.o
	rm TrieTest
	rm TrieTests

test:
	./TrieTests
