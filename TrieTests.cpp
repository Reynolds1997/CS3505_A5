//Evan Parry U1000976, Andrew Fryzel U1070220
//September 26, 2019
//Assignment 4
//This is the tests file for the Trie class.

#include "Trie.h"
#include <vector>
#include "googletest/googletest/include/gtest/gtest.h"
#include "fstream"
#include <iostream>

//fix delete
//fix return all words
TEST(Trie, TestAddAWord)
{
  Trie* trie = new Trie();
  trie->addAWord("testword");


  bool flag = trie->isAWord("testword");
  cout<< flag << " falg"<< endl;

  EXPECT_TRUE(flag);


}

TEST(Trie, TestAdd2WordsDifferent)
{
  Trie* trie = new Trie();
  trie->addAWord("testword");
  trie->addAWord("differentword");

  bool flag = trie->isAWord("testword");
  bool flag2 = trie->isAWord("differentword");

  EXPECT_TRUE(flag);
  EXPECT_TRUE(flag2);


}

TEST(Trie, TestAdd2WordsSimilar)
{
  Trie* trie = new Trie();
  trie->addAWord("testword");
  trie->addAWord("testwords");

  bool flag = trie->isAWord("testword");
  bool flag2 = trie->isAWord("testwords");

  EXPECT_TRUE(flag);
  EXPECT_TRUE(flag2);


}

TEST(Trie, TestAdd5WordsSimilar)
{
  Trie* trie = new Trie();
  trie->addAWord("testword");
  trie->addAWord("testwords");
  trie->addAWord("testwrds");
  trie->addAWord("testworrds");
  trie->addAWord("testwordss");

  bool flag = trie->isAWord("testword");
  bool flag2 = trie->isAWord("testword");
  bool flag3 = trie->isAWord("testwrds");
  bool flag4 = trie->isAWord("testworrds");
  bool flag5 = trie->isAWord("testwordss");

  EXPECT_TRUE(flag);
  EXPECT_TRUE(flag2);
  EXPECT_TRUE(flag3);
  EXPECT_TRUE(flag4);
  EXPECT_TRUE(flag5);


}

TEST(Trie, TestNotAWord)
{
  Trie* trie = new Trie();
  trie->addAWord("testword");


  bool flag = trie->isAWord("testwords");

  EXPECT_FALSE(flag);

}

TEST(Trie, TestNotAWordMultiple)
{
  Trie* trie = new Trie();
  trie->addAWord("testword");
  trie->addAWord("apples");
  trie->addAWord("testwordslonger");
  trie->addAWord("marker");



  bool flag = trie->isAWord("testwords");
  bool flag2 = trie->isAWord("apple");
  bool flag3 = trie->isAWord("marked");

  EXPECT_FALSE(flag);
  EXPECT_FALSE(flag2);
  EXPECT_FALSE(flag3);
}
//prefix test, delete, copy
/*{
  Trie* trie = new Trie();
  trie->addAWord("testword");
  bool flag = trie->isAWord("testword");
  EXPECT_TRUE(flag);
  delete trie;
  flag = trie->isAWord("testword");
  EXPECT_TRUE(flag);
}
*/
TEST(Trie, TestPrefixes)
{
  Trie* trie = new Trie();

  std::string word1 = "marble";
  std::string word2 = "marine";
  std::string word3 = "market";
  std::string word4 = "cat";

  trie->addAWord(word1);
  trie->addAWord(word2);
  trie->addAWord(word3);
  trie->addAWord(word4);

  std::vector<std::string> words;

  words.push_back(word1);
  words.push_back(word2);
  words.push_back(word3);


  std::vector<std::string> prefixWords = trie->allWordsStartingWithPrefix("mar");

  ASSERT_TRUE(words == prefixWords);
}


TEST(Trie, TestPrefixesFalse)
{
  Trie* trie = new Trie();

  std::string word1 = "marble";
  std::string word2 = "marine";
  std::string word3 = "market";
  std::string word4 = "cat";

  trie->addAWord(word1);
  trie->addAWord(word2);
  trie->addAWord(word3);
  trie->addAWord(word4);

  std::vector<std::string> words;

  words.push_back(word1);
  words.push_back(word2);
  words.push_back(word3);



  std::vector<std::string> prefixWords = trie->allWordsStartingWithPrefix("");

  ASSERT_FALSE(words == prefixWords);
}

TEST(Trie, TestPrefixIsAWord)
{
  Trie* trie = new Trie();

  std::string word1 = "caterpillar";
  std::string word2 = "cat";


  trie->addAWord(word1);
  trie->addAWord(word2);

  std::vector<std::string> words;
  words.push_back(word2);

  std::vector<std::string> prefixWords = trie->allWordsStartingWithPrefix("cat");

  ASSERT_TRUE(words == prefixWords);

}

TEST(Trie, TestDuplicateWordsPrefix)
{
  Trie* trie = new Trie();

  std::string word1 = "cat";
  std::string word2 = "cat";


  trie->addAWord(word1);
  trie->addAWord(word2);

  std::vector<std::string> words;
  words.push_back(word2);

  std::vector<std::string> prefixWords = trie->allWordsStartingWithPrefix("cat");

  int size = prefixWords.size();
  ASSERT_EQ(size, 1);

}

TEST(Trie, TestAddingLotsOfWords){

  Trie* t = new Trie();

  std::ifstream file;
	file.open("wordlist.txt");

  //word to be added
  std::string word;

  //add each word to the Trie
  while (file >> word)
  {
    t->addAWord(word);
  //  tt.addAWord(word);
  }


  std::ifstream file2;
	file.open("wordlist.txt");

  while (file >> word)
  {
    ASSERT_TRUE(t->isAWord(word));
  }

}

TEST(Trie, TestPrefixesBigFile)
{

  Trie* t = new Trie();

  std::ifstream file;
	file.open("wordlist.txt");

  //word to be added
  std::string word;

  //add each word to the Trie
  while (file >> word)
  {
    t->addAWord(word);
  //  tt.addAWord(word);
  }

  std::vector<std::string> prefixWords = t->allWordsStartingWithPrefix("abr");

  int size = prefixWords.size();
  ASSERT_EQ(size, 6);

}


TEST(Trie, ReturnEmptyPrefix)
{
  Trie* trie = new Trie();

  std::string word1 = "marble";
  std::string word2 = "marine";
  std::string word3 = "market";
  std::string word4 = "cat";

  trie->addAWord(word1);
  trie->addAWord(word2);
  trie->addAWord(word3);
  trie->addAWord(word4);

  std::vector<std::string> words;

  words.push_back(word4);
  words.push_back(word1);
  words.push_back(word2);
  words.push_back(word3);


  std::vector<std::string> prefixWords = trie->allWordsStartingWithPrefix("");

  ASSERT_TRUE(words == prefixWords);
}


TEST(Trie, SmallCopyConstructor)
{
  Trie originalTrie;

  originalTrie.addAWord("cat");
  originalTrie.addAWord("bird");
  originalTrie.addAWord("armadillo");

  Trie* copyTrie = new Trie(originalTrie);

  ASSERT_TRUE(copyTrie->isAWord("armadillo"));
  ASSERT_TRUE(copyTrie->isAWord("cat"));
  ASSERT_TRUE(copyTrie->isAWord("bird"));
}


TEST(Trie, SmallAssignmentOperator)
{
  Trie originalTrie;

  originalTrie.addAWord("cat");
  originalTrie.addAWord("bird");
  originalTrie.addAWord("armadillo");

  Trie newTrie;

  newTrie.addAWord("dog");
  newTrie.addAWord("fish");
  newTrie.addAWord("emu");

  newTrie = originalTrie;

  ASSERT_TRUE(newTrie.isAWord("armadillo"));
  ASSERT_TRUE(newTrie.isAWord("cat"));
  ASSERT_TRUE(newTrie.isAWord("bird"));

  ASSERT_FALSE(newTrie.isAWord("dog"));
  ASSERT_FALSE(newTrie.isAWord("emu"));
  ASSERT_FALSE(newTrie.isAWord("fish"));

}
