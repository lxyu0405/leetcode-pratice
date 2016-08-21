#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <map>

using namespace std;

#define ALPHA_SIZE 26;

int main(){
    string key;
    cin >> key;
    vector<bool> word(26, false);
    vector<char> code;
    queue<char> wordOrder;
    //replace
    for (auto c : key) {
        word[c-'A'] = true;
        if (c == 'J') {
            wordOrder.push('I');
        }else{
            wordOrder.push(c);
        }
    }
    
    word['J'-'A'] = true;
    
    vector<bool> wordMark(26, false);
    wordMark['J'-'A'] = true;
    
    while (!wordOrder.empty()) {
        char c = wordOrder.front();
        wordOrder.pop();
        if (!wordMark[c-'A']) {
            wordMark[c-'A'] = true;
            code.push_back(c);
        }
    }
    
    // other words
    for (int i = 0; i < 26; i++) {
        if (!word[i]) {
            code.push_back((char)'A'+i);
        }
    }
    
    for (int i = 0; i < code.size(); i++) {
        cout << code[i];
        if ((i+1) % 5 == 0) {
            cout << endl;
        }
    }
    
    return 0;
}
