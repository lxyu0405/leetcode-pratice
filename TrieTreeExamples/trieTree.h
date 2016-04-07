//
//  trieTree.h
//  Cpp-Exam
//
//  Created by luxy on 4/7/16.
//  Copyright © 2016 luxy. All rights reserved.
//

#ifndef trieTree_h
#define trieTree_h


#include <iostream>      // cout, endl
#include <string>        // string ops
#include <cstdlib>       // NULL
#include <algorithm>     // max

using namespace std;


struct trieNodeType{
    char            keyValue;
    bool            endWordMark;
    unsigned int    wordCount;
    trieNodeType    *children[26];
    
};

class trieTree
{
public:
    // Constructor
    // Postcondition: tree initialized, root = NULL
    trieTree();
    
    // Destructor
    // Postcondition: Tree is deleted, all memory is deallocated, by calling private destroyTree()
    ~trieTree();
    
    // public countNodes will call private countNodes()
    // Postcondition: return the total cound of nodes in tree by calling private CountNodes()
    unsigned int countNodes() const;
    
    // public coundWords()calls the private countWords()
    // Postcondition: returns the total count of words  by calling the private countWords()
    unsigned int countWords() const;
    
    // Public height() calls the private height()
    // Postcondition: returns the height of the tree
    unsigned int height() const;
    
    // Public insert(), insert passed word into the trie tree, will mark end of word as appropriate
    // Postcondition: Passed word is inserted into trieTree, end of word is marked when appropriate
    void insert(string);
    
    // Public search(),determine if the passed string is a word in the tree
    // Postcondition: serach() will return true if word is found, false otherwise
    bool search(string) const;
    
    // Public incCount(), will increment word count for passed word and return true
    // Postcondition: true is returned if word is found, false other wise, count is incremented
    bool incCount(string) const;
    
    // Public printTree(), call the private printTree()
    // Postcondition: trieTree is printed
    void printTree() const;
    
    // Public getWordCount(), return word count for passed word, 0 if not found.
    // Postcondition: word count of passed word is returned, zero is returned if word not found
    unsigned int getWordCount(string) const;
    
    // Public getMaxNode(), calls private get getMaxNode()
    // Postcondition: will return wrod and count for the node with the highest word count value
    void getMaxNode( unsigned int&, string&) const;
    
private:
    
    // Private countNodes(), will return total count of nodes
    // Postcondition: total count of nodes is returned to public countNodes()
    unsigned int countNodes(trieNodeType*) const;
    
    // Private coundWords(), will return total count of words
    // Postcondition: total count of words is returned to public countWords()
    unsigned int countWords(trieNodeType*) const;
    
    // Private getMaxNode(), returns word and count for largest word count value
    // Postcondition: will return wrod and count for the node with the highest word count value
    void getMaxNode(trieNodeType*, unsigned int&, string, string&) const;
    
    // Private height() return maximum height of tree
    // Postcondition: returns the height of the tree to public height()
    unsigned int height(trieNodeType*) const;
    
    // Private destroyTree() will delete tree
    // Postcondition: Tree is deleted, all memory is deallocated
    void destroyTree(trieNodeType* );
    
    // Private printTree(), prints tree
    // Postcondition: trieTree is printed
    void printTree(trieNodeType*, string) const;
    
    // root points to tree
    trieNodeType* root;
    
};

#endif /* trieTree_h */
