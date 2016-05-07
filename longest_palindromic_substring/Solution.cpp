#include <vector>
#include <string>
#include <iostream>

using namespace std;

class Solution {
public:
    string longestPalindrome(string s) {
        if (s.length() < 2) {
            return s;
        }
        int maxLen = 1, start = 0;
        vector<vector<bool>> isPal(s.length(), vector<bool>(s.length(), false));
        isPal[0][0] = true;
        for (int i = 1; i < s.length(); i++) {
            for (int j = 0; j <= i; j++) {
                if (s[i] == s[j] && (i - j <= 2 || isPal[i-1][j+1])) {
                    //longest = longest.length() < (i-j+1) ? s.substr(j,i-j+1) : longest;
                    isPal[i][j] = true;
                    if (i-j+1 > maxLen) {
                        maxLen = i-j+1;
                        start = j;
                    }
                }
            }
        }
        return s.substr(start, maxLen);
    }
};
