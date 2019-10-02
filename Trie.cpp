//Evan Parry U1000976, Andrew Fryzel U1070220
//September 26, 2019
//Assignment 4
//This is the Trie implementation.

#include <string>

#include <iostream>

#include "Trie.h"
#include <map>
using namespace std;

//Constructor
Trie::Trie()
{
	//  Trie * node = new Trie;
	//  Trie node;
	isEnd = false;

}


//Adds a word to the trie.
void Trie::addAWord(std::string input)
{

	Trie currentNode;

	//Iterate through the string character by character
	for (unsigned int i = 0; i < input.length(); i++)
	{

		char currentChar = input[i];

		//If a node with the char doesn't exist, make a new Trie
		if (currentNode.trieMap.find(currentChar) == currentNode.trieMap.end())
		{
			Trie insert;
			currentNode.trieMap[currentChar] = insert;
		}

		//Iterate to the next node - either one that already exists, or one that
		//was created in the above if statement.
		Trie* tPtr = &currentNode;
		//Otherwise, we'll just move on to the next character
		tPtr->trieMap[currentChar];
	}

	currentNode.isEnd = true;
}

//Checks if a given word is already stored in the trie.
bool Trie::isAWord(std::string input)
{
	Trie currentNode;


	//Iterate through the word character by character
	for (unsigned int i = 0; i < input.length(); i++)
	{
		char currentChar = input[i];

		auto it = currentNode.trieMap.find(currentChar);
		if (it == currentNode.trieMap.end())
		{

			//If a node with the given key x doesn't exist, we return false
			//if(currentNode.trieMap.find(currentChar) == currentNode.trieMap.end()){
			return false;
		}
		Trie* tPtr = &currentNode;
		//Otherwise, we'll just move on to the next character
		tPtr->trieMap[currentChar];

	}

	//Once we're at the end, we return the status of the end node.
	//For example, this prevents a search for "cat" from returning true if
	//"caterpillar" is present but "cat" is not.
	return currentNode.isEnd;
}

//Helper method that returns a vector of child words stemming from the given original string.
void Trie::prefixHelper(std::vector<std::string>& vector, std::string originalPrefix,
	Trie node)
{

	//We start with the prefix as our entire word
	std::string currentWord = originalPrefix;


	//If we've reached the end of a word, we want to add that word to the vector.
	if (node.isEnd == true)
	{
		vector.push_back(currentWord);
	}

	//Aim our first node at the provided root
	Trie& currentNode = node;


	//We want to recur across the children nodes. Using an auto iterator
	//Lets us only look at data stored in the map, so we don't need to worry
	//about nullptrs
	for (auto iter : trieMap)
	{
		//Take the character key from the iterator
		currentWord += iter.first;
		prefixHelper(vector, currentWord, currentNode);
		currentWord = originalPrefix; //Resets the word after a recursive call is done
	}
}

//Returns a string vector containing all strings in the Trie that begin with the given prefix.
//If the input string is blank, the string vector contains every string in the trie
std::vector<std::string> Trie::allWordsStartingWithPrefix(std::string prefix)
{


	//Create a return vector and point to the root node.
	std::vector<std::string> returnVector;
	Trie currentNode;


	for (unsigned int i = 0; i < prefix.length(); i++)
	{

		char currentChar = prefix[i];

		//If the prefix does not exist, we just want to return the empty vector.
		if (currentNode.trieMap.find(currentChar) == currentNode.trieMap.end())
		{
			return returnVector;
		}
		Trie* tPtr = &currentNode;
		//Otherwise, we'll just move on to the next character
		tPtr->trieMap[currentChar];


		//Otherwise, we'll have reached the end and node will be pointing at the right spot.
	}
	prefixHelper(returnVector, prefix, currentNode);


	return returnVector;
}
