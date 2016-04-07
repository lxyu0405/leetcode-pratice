//
//  wordCount.hpp
//  Cpp-Exam
//
//  Created by luxy on 4/7/16.
//  Copyright © 2016 luxy. All rights reserved.
//

#ifndef wordCount_hpp
#define wordCount_hpp


#include <iostream>                  // Provides cout
#include <algorithm>                 // Provides max
#include <cstdlib>                   // Provides NULL
#include <cassert>                   // Provides assert
#include <string>
#include "trieTree.h"

using namespace std;

class wordCount{
public:
    
    // constructor will initilizie  totalWordCount and docFileName
    wordCount();
    
    bool readDocument(const string);
    // The readDocument() function should attempt to open the passed file name, and if
    // successful read the document one word. Each word should be added to to the Trie-Tree
    // tree which will create new nodes for unique words and update the count for duplicate
    // words.The function should remove any brackets, numbers, or punctuation from the words
    // (e.g., '(', '{', '[', ')', '}', ']', '!', '?', '.', ':', '$', '#', etc.). Additionally,
    // numbers should be filtered out. For example, 'Hello!' would be stored as 'hello'. All
    // words should be converted to lower case. This will count 'Hello' and 'hello' as the same word.
    // Additionally, the word '1234', 'p@asw0rd', 're­did', and 'count12er' should be ignored
    // (i.e. not stored in the tree). The function should update the total word count
    // (including duplicate words). See the sample output for examples. If the open and read
    // are successful, the function should return true and false otherwise.
    // The function should close the file.
    
    void showDocumentFileName() const;
    // showDocumentFileName() function should display the formatted document file name. See the sample output for formatting.
    
    void showTotalWordCount() const;
    //  showTotalWordCount() function should display the formatted total word count. See the sample output for formatting.
    
    
    void showUniqueWordCount() const;
    // The showUniqueWordCount() function should display the formatted unique word count by calling the red-black tree countNodes() function.
    
    void showTreeNodeCount() const;
    // The showTreeNodeCount() function should display the formatted total number of nodes in the red-black tree.
    
    void showTreeHeight() const;
    // showTreeHeight() function should display the formatted maximum height of the red- black tree.
    
    void getMaxNode(unsigned int &, string &);
    //  getMaxNode() function should return the node, word count and word, with the largest word count.
    
    void printTree() const;
    // The printTree() function should print the tree in pre-order format.
    
    unsigned int getWordCount(string) const;
    // The getWordCount() function should return the count of the passed word (0 if not found).
    
private:
    unsigned int totalWordCount;
    // will hold the total number of words
    
    string docFileName;
    // will hold the filename of the text to be searched
    
    trieTree wordTree;
    // tree which will hold the words
    
};


#endif /* wordCount_hpp */
