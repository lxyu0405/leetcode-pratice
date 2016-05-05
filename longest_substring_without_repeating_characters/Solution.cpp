#include <vector>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <iostream>

using namespace std;

// unordered_set<char>
class Solution {
public:
    // Two pointers
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int> chars;
        int longest = 0;
        int pre = 0, thisLen = 0;
        for (int i = 0; i < s.length(); i++) {
            if (chars.count(s[i])) {
                for (int j = pre; j < chars[s[i]]; j++) {
                    chars.erase(s[j]);
                }
                pre = chars[s[i]] + 1;
                thisLen = i - pre + 1;
            }else{
                thisLen++;
            }
            chars[s[i]] = i;
            longest = thisLen > longest ? thisLen : longest;
        }
        return longest;
    }
    
    //TLE O(n^2)
    int lengthOfLongestSubstringDP(string s) {
        if (s.length() < 2) {
            return (int)s.length();
        }
        
        vector<int> longestByThis(s.length(),1);
        for (int i = 1; i < s.length(); i++) {
            unordered_set<char> chars;
            chars.insert(s[i]);
            for (int j = i-1; j >= 0; j--) {
                if (chars.find(s[j]) == chars.end()) {
                    longestByThis[i]++;
                    chars.insert(s[j]);
                }else{
                    break;
                }
            }

        }
        int longest = longestByThis[0];
        for (auto len : longestByThis) {
            longest = len > longest ? len : longest;
        }
        return longest;
    }
};
