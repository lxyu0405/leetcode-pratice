#include <vector>
#include <string>
#include <unordered_set>
#include <iostream>

using namespace std;

class Solution {
public:
    string reverseVowels(string s) {
        if (s.length() < 2) {
            return s;
        }
        unordered_set<char> vowels ({'a', 'A', 'e', 'E', 'i', 'I', 'o', 'O', 'u', 'U'});
        int begin = 0, end = s.length()-1;
        while (begin < end) {
            if (vowels.count(s[begin]) && vowels.count(s[end])) {
                swapCharsInString(s, begin, end);
                begin++, end--;
            }else if (vowels.count(s[begin])){
                end--;
            }else if (vowels.count(s[end])) {
                begin++;
            }else{
                begin++, end--;
            }
        }
        return s;
    }
private:
    void swapCharsInString(string& s, int a, int b){
        char temp = s[a];
        s[a] = s[b];
        s[b] = temp;
    }
};

int main(){
    Solution test;
    test.reverseVowels("HEllo");
    return 0;
}
