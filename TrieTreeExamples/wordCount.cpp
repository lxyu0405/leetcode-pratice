//
//  wordCount.cpp
//  Cpp-Exam
//
//  Created by luxy on 4/7/16.
//  Copyright © 2016 luxy. All rights reserved.
//

#include "wordCount.hpp"

#include <iostream>                  // Provides cout
#include <algorithm>                 // Provides max
#include <cstdlib>                   // Provides NULL
#include <cassert>                   // Provides assert
#include <string>
#include <fstream>
#include <cstddef>

using namespace std;

//wordCount imp file

//Constructor
wordCount::wordCount(){
    totalWordCount = 0;
    docFileName = "";
}

// Read document
// Passed argument string fileName will hold the name of the file
bool wordCount::readDocument(const string fileName){
    docFileName = fileName;
    ifstream listOfWords(fileName.c_str());                         // listOfWords contains file
    
    if (!listOfWords) {                                     // If file is not valid return false
        cout << "Error could not open file " <<endl;
        return false;
    }
    else{
        string dictionaryWord;                              // Dictionary word to be stored
        listOfWords >> dictionaryWord;                      // Read first word
        
        bool isItAlpha = true;
        
        string doNotInsert = "";
        string dontSend ="";
        
        while (!listOfWords.eof()) {
            for (int i = 0; i < dictionaryWord.length(); i++) {
                if (!isalpha(dictionaryWord[i])) {
                    isItAlpha = false;
                    break;
                }
                dictionaryWord[i] = tolower(dictionaryWord[i]);
            }
            if (isItAlpha) {
                wordTree.insert(dictionaryWord);
                totalWordCount++;
            }
            isItAlpha = true;
            listOfWords >> dictionaryWord;
        }
    }
    return true;
}

// Show doc file name
void wordCount::showDocumentFileName() const{
    cout<< "Document File Name: " << docFileName << endl;
}

// *****************************************************************
// *****************************************************************
// Show total count
void wordCount::showTotalWordCount() const{
    cout<< "Total Word Count: " << totalWordCount <<endl;
}

// Show unique word count
void wordCount::showUniqueWordCount() const{
    cout <<"Unique Word Count: " << wordTree.countWords() << endl;
}

// show tree height
void wordCount::showTreeHeight() const{
    cout <<"Tree Height: " << wordTree.height() << endl;
}

// tree count
void wordCount::showTreeNodeCount() const{
    cout << "Tree Node Count: " << wordTree.countNodes() << endl;
}

// get max node
// passed arguments int&x will hold the number of the maxnode, and string&y will hold the word with the maxnode
void wordCount::getMaxNode(unsigned int& x, string& y){
    x = 0;
    y = "";
    wordTree.getMaxNode(x, y);
}

// print tree
void wordCount::printTree() const{
    wordTree.printTree();    
}

// get word count
// the passed argument string theWord will hold the word for which we are searching the count for
unsigned int wordCount::getWordCount(string theWord) const{
    for (int i = 0; i < theWord.length(); i++) {
        if (!isalpha(theWord[i])) {
            return 0;
        }
        theWord[i] = tolower(theWord[i]);
    }
    return wordTree.getWordCount(theWord);
    
}
