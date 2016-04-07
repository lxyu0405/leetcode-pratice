//
//  trieTree.cpp
//  Cpp-Exam
//
//  Created by luxy on 4/7/16.
//  Copyright © 2016 luxy. All rights reserved.
//

#include <stdio.h>
#include <iostream>      // cout, endl
#include <string>        // string ops
#include <cstdlib>       // NULL
#include <algorithm>     // max

#include "trieTree.h"

using namespace std;

// Constructor
// Postcondition: tree initialized, root = NULL
trieTree:: trieTree(){
    trieNodeType *node = new trieNodeType;          // new node
    root =  node;                                   // root points to node
    root -> keyValue = 45;                         // keyValue holds a space
    root -> endWordMark = false;                    // endWordMark = false
    
    for (int i = 0; i < 26; i++) {
        root ->children[i] = NULL;                 // NULLify all the little ones
        //root ->children[i] -> wordCount =0;
    }
}

// Destructor
// Postcondition: Tree is deleted, all memory is deallocated, by calling private destroyTree()
trieTree::~trieTree(){
    destroyTree(root);
}


// Private destroyTree() will delete tree
// Postcondition: Tree is deleted, all memory is deallocated
void trieTree::destroyTree(trieNodeType* node ){
    
    if (node != NULL) {
        for (int i = 0; i < 26; i++) {
            destroyTree(node->children[i]);
        }
        delete node;
        node = NULL;
    }
    
}

// public countNodes will call private countNodes()
// Postcondition: return the total cound of nodes in tree by calling private CountNodes()
unsigned int trieTree::countNodes() const{
    return countNodes(root);
}

// Private countNodes(), will return total count of nodes
// Postcondition: total count of nodes is returned to public countNodes()
unsigned int trieTree::countNodes(trieNodeType* node) const{
    int totalCount = 0;                         // will hold node count
    if (node == NULL) {
        return totalCount;                      // if node is NULL return the count
    }
    for (int i = 0; i < 26; i++) {
        totalCount += countNodes(node->children[i]);
    }
    
    return 1 + totalCount;                      // will return total count
}

// public coundWords()calls the private countWords()
// Postcondition: returns the total count of words  by calling the private countWords()
unsigned int trieTree::countWords() const{
    return countWords(root);
}


// Private coundWords(), will return total count of words
// Postcondition: total count of words is returned to public countWords()
unsigned int trieTree::countWords(trieNodeType* node) const{
    
    int totalCount = 0;
    if (node == NULL) {
        return totalCount;
    }
    for (int i = 0; i < 26; i++) {
        if (node->children[i] == NULL ) {
            //do nothing
        }
        else{
            if (node -> children[i] -> endWordMark == true) {
                totalCount++;
            }
            totalCount += countWords(node ->children[i]);
        }
    }
    
    return  totalCount;
}

// Public height() calls the private height()
// Postcondition: returns the height of the tree
unsigned int trieTree::height() const{
    return height(root);
}


// Private height() return maximum height of tree
// Postcondition: returns the height of the tree to public height()
unsigned int trieTree::height(trieNodeType* x) const{
    if (x == NULL) {
        return 0;
    }
    
    int maxHeight = 0;
    int treeDepth = 0;
    
    for (int i = 0; i < 26; i++) {
        treeDepth = height(x ->children[i]);
        if (treeDepth > maxHeight) {
            maxHeight = treeDepth;
        }
    }
    
    return  1+ maxHeight;
}

// Public insert(), insert passed word into the trie tree, will mark end of word as appropriate
// Postcondition: Passed word is inserted into trieTree, end of word is marked when appropriate
void trieTree::insert(string newKey){
    
    trieNodeType *currentNode = root;                           // Traversal pointer
    trieNodeType *newNodeToInsert;                              // Pointer for new node to be inserted, thus name
    int letterIndex = 0;                                        // index where letter will be placed
    int keyLength = newKey.length();                            // length of new word to insert
    
    if (root != NULL) {
        for (int i = 0; i < keyLength; i++) {                       // loop through each letter of word
            letterIndex = newKey[i] - 'a';                       // get the index of the letter
            
            if (currentNode -> children[letterIndex] == NULL) {     // only insert if NULL
                newNodeToInsert = new trieNodeType;                 // new node, maybe move this up before for loop
                newNodeToInsert -> endWordMark = false;             // set to false, true after loop
                newNodeToInsert -> keyValue = newKey[i];        // insert current letter in new node key val
                newNodeToInsert -> wordCount = 0;
                
                for (int k = 0; k < 26; k++) {
                    newNodeToInsert -> children[k] = NULL;                 // NULLify the little ones
                }
                currentNode -> children[letterIndex] = newNodeToInsert;
            }
            currentNode = currentNode -> children[letterIndex];         // got to next node for next insert
        }
        currentNode -> endWordMark = true;                          // end of word once for loop is done
        currentNode -> wordCount++;
    }
}

// Public search(),determine if the passed string is a word in the tree
// Postcondition: serach() will return true if word is found, false otherwise
bool trieTree::search(string key) const{
    if (root != NULL) {
        trieNodeType* traverse = root;                  // set traversal pointer to root
        int keyLength = key.length();                   // lenght of word to be searched for
        int letterIndex;                                // index of where to look for letter
        for (int i = 0; i <keyLength; i++) {
            letterIndex = key[i] - 'a';           // index of where letter should be
            
            if (traverse -> children[letterIndex] != NULL) {
                traverse = traverse -> children[letterIndex];
            }else{
                return false;
            }
        }
        return traverse->endWordMark;
    }
    return false;
}

// Public incCount(), will increment word count for passed word and return true
// Postcondition: true is returned if word is found, false other wise, count is incremented
bool trieTree::incCount(string key) const{
    if (root != NULL) {
        trieNodeType* traverse = root;                  // set traversal pointer to root
        int keyLength = key.length();                   // length of word to be searched for
        int letterIndex;                                // index of where to look for letter
        for (int i = 0; i < keyLength; i++) {                       // loop through each letter of word
            letterIndex = key[i] - 'a';                       // get the index of the letter
            
            if (traverse -> children[letterIndex] == NULL) {     // if NULL at any point, DNE.
                return false;
            }
            traverse = traverse -> children[letterIndex];         // got to next node for next letter
        }
        traverse -> wordCount++;
        return true;
    }
    return false;
}

// Public printTree(), call the private printTree()
// Postcondition: trieTree is printed
void trieTree::printTree() const{
    string que;
    printTree(root,que);
}

// Private printTree(), prints tree
// Postcondition: trieTree is printed
void trieTree::printTree(trieNodeType* node, string buildingWord) const{
    if (node == NULL) {
        return;
    }
    for (int i = 0; i < 26; i++) {
        if (node->children[i] == NULL ) {
            //do nothing
        }
        else{
            buildingWord += (i+'a');
            if (node -> children[i] -> endWordMark) { // this word ends here
                cout << buildingWord << " " << node->children[i]->wordCount << endl;
            }
            printTree(node ->children[i], buildingWord);
            buildingWord = buildingWord.substr(0, buildingWord.size()-1);
        }
    }
}

// Public getWordCount(), return word count for passed word, 0 if not found.
// Postcondition: word count of passed word is returned, zero is returned if word not found
unsigned int trieTree::getWordCount(string key) const{
    if (root != NULL) {
        trieNodeType* traverse = root;                  // set traversal pointer to root
        int keyLength = key.length();                   // length of word to be searched for
        int letterIndex;                                // index of where to look for letter
        for (int i = 0; i < keyLength; i++) {
            letterIndex = key[i] - 'a';           // index of where letter should be
            if (traverse->children[letterIndex] != NULL) {
                traverse = traverse -> children[letterIndex];
            }else{
                return 0;
            }
        }
        
        if (traverse->endWordMark) {                    // word ends here
            return traverse -> wordCount;               // return wordCount
        }else{
            return 0;
        }
    }
    return 0;
}

// Public getMaxNode(), calls private get getMaxNode()
// Postcondition: will return wrod and count for the node with the highest word count value
void trieTree::getMaxNode( unsigned int& maxNode, string& maxWord) const{
    maxNode = 0;
    maxWord= "";
    string temp = "";
    getMaxNode(root, maxNode, temp, maxWord);
}

// Private getMaxNode(), returns word and count for largest word count value
// Postcondition: will return word and count for the node with the highest word count value
void trieTree::getMaxNode(trieNodeType* node, unsigned int& maxNode, string buildingWord, string& maxWord) const{
    if (node == NULL) {
        return;
    }
    
    for (int i = 0; i < 26; i++) {
        if (node->children[i] == NULL ) {
            //do nothing
        }
        else{
            buildingWord += (i+'a');
            if (node -> children[i] -> endWordMark) {                   // word ends here
                if (maxNode < node->children[i]->wordCount) {
                    maxNode = node->children[i]->wordCount;
                    maxWord = buildingWord;
                }
            }
            getMaxNode(node ->children[i], maxNode, buildingWord, maxWord);
            buildingWord = buildingWord.substr(0, buildingWord.size()-1);
        }
    }
}