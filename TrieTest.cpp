#include <fstream>
#include <iostream>
#include "Trie.h"

using namespace std;

int main(int argc, char const *argv[]) {
  /* code */

  if(argc < 2){
    cout << "Please use two arguments." << endl;
    return 0;
  }

  string fileName1 = argv[1];
  string fileName2 = argv[2];

  ifstream inputFile1(fileName1);

  Trie* baseTrie = new Trie();
  if(inputFile1.is_open() && inputFile1.good()){
    string lineHolder = "";
    while(getline(inputFile1, lineHolder)){
      //lineHolder+="\n";
      baseTrie->addAWord(lineHolder);
    }
  }

  //Print statements for testing purposes.
  /*
  cout << "Printing all words contained in the first input file: " << endl;
  vector<string> file1Vector = baseTrie->allWordsStartingWithPrefix("");
  for(int i = 0; i < file1Vector.size(); i++){
    cout << "   " << file1Vector.at(i) << endl;
  }

  cout << "Printing prefix search results from file 1:" << endl;
  string prefix = "mar";
  vector<string> testVector1 = baseTrie->allWordsStartingWithPrefix(prefix);
  for(int i = 0; i < testVector1.size(); i++){
    cout << "   " << testVector1.at(i) << endl;
  }
  */

/*
  cout << "Creating new, duplicate trie via assignment operator and printing words: " << endl;
  Trie* newTrie(baseTrie);

  //Print statement for testing purposes.
  vector<string> testVector2 = newTrie->allWordsStartingWithPrefix("");
  for(int i = 0; i < testVector2.size(); i++){
    cout << "   " << testVector2.at(i) << endl;
  }


  cout << "Deleting duplicate trie." << endl;
  newTrie->~Trie();
  cout << "Trie deleted." << endl;

cout << "Words from original Trie: " << endl;
vector<string> testVector3 = newTrie->allWordsStartingWithPrefix("");
for(int i = 0; i < testVector3.size(); i++){
  cout << "   " << testVector3.at(i) << endl;
}
*/
cout << "Creating secondTrie Trie. Showing entries." << endl;
Trie* secondTrie = new Trie();
secondTrie->addAWord("testa");
secondTrie->addAWord("testb");
vector<string> secondTrieVector = secondTrie->allWordsStartingWithPrefix("");
cout << secondTrieVector.at(0) << endl;
cout << secondTrieVector.at(1) << endl;

secondTrie = baseTrie;

cout << "Set secondTrie equal to baseTrie. Showing first two entries:" << endl;
vector<string> secondTrieVector2 = secondTrie->allWordsStartingWithPrefix("");
cout << secondTrieVector2.at(0) << endl;
cout << secondTrieVector2.at(1) << endl;



ifstream inputFile2(fileName2);

cout << "Searching for words from file 2." << endl;
  if(inputFile2.is_open() && inputFile2.good()){
    string lineHolder = "";
    while(getline(inputFile2, lineHolder)){
      //lineHolder+="\n";
      if(baseTrie->isAWord(lineHolder)){
        cout << lineHolder << " was found." << endl;
      }
      else{
        cout << lineHolder << " was not found. Did you mean: " << endl;
        vector<string> stringVector = baseTrie->allWordsStartingWithPrefix(lineHolder);
        if(stringVector.size() == 0){
          cout << "   No alternatives found." << endl;
        }
        else{
          for(unsigned int i = 0; i < stringVector.size(); i++){
            cout << "   " << stringVector.at(i) << endl;
          }
        }
      }

    }
  }

  return 0;
}
