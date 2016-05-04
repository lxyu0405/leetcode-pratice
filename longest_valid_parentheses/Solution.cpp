#include <vector>
#include <string>
#include <stack>
#include <utility>
#include <iostream>

using namespace std;

class Solution {
public:
    int longestValidParentheses(string s) {
        if (s.length() < 2) {
            return 0;
        }
        
        stack<pair<char, int>> bracketStack;
        vector<int> longestPare(s.length(),0);
        // Initialization
        longestPare[0] = 0;
        if (s[0] == '(') {
            bracketStack.push({'(',0});
        }
        // Use a stack to find parentheses pairs 
        for (int i = 1; i < s.length(); i++) {
            if (s[i] == '(') {
                bracketStack.push({'(',i});
            }else{
                // s[i] == ')'
                if (!bracketStack.empty()) {
                    auto topPair = bracketStack.top();
                    if (topPair.first == '(') {
                        bracketStack.pop();
                        longestPare[topPair.second] = 1;
                        longestPare[i] = 1;
                    }
                }
            }
        }
        // Analyze the longest sequence
        int longest = 0;
        int pre = 0, now = 0;
        for (; now < s.length(); now++) {
            if (longestPare[now] == 1) {
                pre = now;
                while (now < s.length() && longestPare[now] == 1) {
                    now++;
                }
                int thisLength = now - pre;
                longest = longest > thisLength ? longest : thisLength;
            }
        }
        return longest;
    }
};
