#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    int maxProduct(vector<string>& words) {
        vector<unsigned int> bitWords;
        for (auto word : words) {
            bitWords.push_back(stringToBits(word));
        }
        int max = 0;
        for (int i = 0; i < words.size(); i++) {
            for (int j = i + 1; j < words.size(); j++) {
                if (!(bitWords[i] & bitWords[j])) {
                    int thisProduct = words[i].length() * words[j].length();
                    max = thisProduct > max ? thisProduct : max;
                }
            }
        }
        return max;
    }
    
    unsigned int stringToBits(const string word){
        unsigned int bits = 0;
        for (char cha : word) {
            int index = cha - 'a';
            bits |= (1 << (25-index));
        }
        return bits;
    }
};

int main(){
    //"abcw", "baz", "foo", "bar", "xtfn", "abcdef"
    vector<string> words;
    words.push_back("abcw");
    words.push_back("baz");
    words.push_back("foo");
    words.push_back("bar");
    words.push_back("xtfn");
    words.push_back("abcdef");
    
    Solution test;
    cout << test.maxProduct(words) << endl;
}
