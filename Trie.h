//Evan Parry U1000976, Andrew Fryzel U1070220
//September 26, 2019
//Assignment 4
//This is the header file for the Trie class.


#ifndef TRIE_H


#define TRIE_H

#include <string>
#include <vector>
#include <map>
//#include <map>
using namespace std;

class Trie {

public:

  bool isEnd;
  map<char, Trie> trieMap;

  Trie();



  void addAWord(std::string);
  bool isAWord(std::string);

  std::vector<std::string> allWordsStartingWithPrefix(std::string);

  void prefixHelper(std::vector<std::string>&, std::string, Trie const);

};

#endif
