#include <iostream>
#include <string>
#include <sstream>
#include <vector>

using namespace std;

class Solution {
public:
    bool wordPattern(string pattern, string str) {
        vector<string> words;
        splitStrBySpaces(str, words);
        if (words.size() == 1) {
            return pattern.length() == 1 ? true : false;
        }
        if (words.size() != pattern.length()) {
            return false;
        }
        for (int i = 0; i < pattern.length(); i++) {
            for (int j = i + 1; j < pattern.length(); j++) {
                if ((pattern[i] == pattern[j] && words[i] == words[j]) || (pattern[i] != pattern[j] && words[i] != words[j])) {
                    continue;
                }else{
                    return false;
                }
            }
        }
        return true;
    }
    
    void splitStrBySpaces(const string str, vector<string>& words){
        istringstream iss(str);
        copy(istream_iterator<string>(iss), istream_iterator<string>(), back_inserter(words));
    }
};

int main(){
    Solution test;
    cout << test.wordPattern("jquery", "jquery") << endl;
    return 0;
}
