//
//  AllTest.cpp
//  Cpp-Exam
//
//  Created by luxy on 4/7/16.
//  Copyright © 2016 luxy. All rights reserved.
//

/*
#include <iostream>
#include <fstream>
#include <string>

#include "trieTree.h"
#include "wordCount.hpp"

using namespace std;

int main()
{
    
    // *****************************************************************
    //  Headers...
    
    string	bars, stars;
    bars.append(65, '-');
    stars.append(65, '*');
    
    cout << bars << endl << "**** Test Starts *******" << endl;
    cout << endl;
    
    wordCount	myDoc2;
    unsigned int	max2;
    string word2;
    string testDoc2 = "/Users/luxy/Desktop/nv.txt";
    
    if (myDoc2.readDocument(testDoc2) ) {
        myDoc2.showTotalWordCount();
        myDoc2.showUniqueWordCount();
        myDoc2.showTreeNodeCount();
        myDoc2.showTreeHeight();
        myDoc2.showDocumentFileName();
        myDoc2.getMaxNode(max2, word2);
        cout << endl;
        
        cout << "Most Frequent Word is: \"" << word2 << "\", occurring " << max2 << " times." << endl << endl;
        
        cout << "Count for 'Nevada': " <<
        myDoc2.getWordCount("Nevada") << endl;
        cout << "Count for 'State': " <<
        myDoc2.getWordCount("State") << endl;
        cout << "Count for 'or': " <<
        myDoc2.getWordCount("or") << endl;
        cout << "Count for 'calendar': " <<
        myDoc2.getWordCount("calendar") << endl;
        cout << "Count for 'amended': " <<
        myDoc2.getWordCount("amended") << endl;
        cout << "Count for 'chamber': " <<
        myDoc2.getWordCount("chamber") << endl;
        cout << "Count for 'things': " <<
        myDoc2.getWordCount("things") << endl;
        cout << "Count for 'Home': " <<
        myDoc2.getWordCount("Home") << endl;
    }
    cout << endl;
    
    cout << bars << endl << "**** Test Done! *******" << endl;
    
    return 0;
}
*/

