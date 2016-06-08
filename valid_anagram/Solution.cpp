#include <string>
#include <unordered_map>
#include <iostream>

using namespace std;

class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.length() != t.length()) {
            return false;
        }
        unordered_map<char, int> chars;
        for (char c : s) {
            if (chars.count(c)) {
                chars[c]++;
            }else{
                chars[c] = 1;
            }
        }
        for (char c: t) {
            if (chars.count(c)) {
                chars[c]--;
                if (chars[c] == 0) {
                    chars.erase(c);
                }
            }else{
                return false;
            }
        }
        return chars.empty() ? true : false;
    }
};
