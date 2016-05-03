#include <vector>
#include <sstream>
#include <string>
#include <iostream>

using namespace std;

class Solution {
public:
    int minCut(string s) {
        if (s.length() < 2) {
            return 0;
        }
        int len = s.length();
        vector<int> minCutNow(len, len);
        vector<vector<bool>> isPal(len, vector<bool>(len, false));
        minCutNow[0] = 0, isPal[0][0] = true;
        for (int i = 1; i < s.length(); i++) {
            for (int j = 0; j <= i; j++) {
                if (s[j] == s[i] && (i - j < 2 || isPal[j+1][i-1])) {
                    isPal[j][i] = true;
                    if (isPal[0][i]) {
                        minCutNow[i] = 0;
                    }else{
                        minCutNow[i] = (minCutNow[j-1] + 1) < minCutNow[i] ? (minCutNow[j-1] + 1) : minCutNow[i];
                    }
                }
            }
        }
        return minCutNow[s.length()-1];
    }
};
/*Time Limit exceed. Another DP structure is necessary
vector<int> minCutNow(s.length()+1, INT32_MAX);
minCutNow[0] = -1, minCutNow[1] = 0;
for (int i = 2; i <= s.length(); i++) {
    for (int j = 1; j <= i; j++) {
        string thisSub = s.substr(j, i-j+1);
        if (isPalindrome(thisSub)) {
            minCutNow[i] = (minCutNow[j-1] + 1) < minCutNow[i] ? (minCutNow[j-1] + 1) : minCutNow[i];
        }
    }
}
return minCutNow[s.length()];
// Function
bool isPalindrome(string sub){
    if (sub.length() == 1) {
        return true;
    }
    for (int i = 0; i < sub.length()/2; i++) {
        if (sub[i] != sub[sub.length()-1-i]) {
            return false;
        }
    }
    return true;
}*/
