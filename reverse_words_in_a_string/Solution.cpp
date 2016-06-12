#include <string>
#include <vector>
#include <stack>
#include <iostream>

using namespace std;

class Solution {
public:
    void reverseWords(string &s) {
        int beh = 0, now = 0;
        string res = "";
        for (int i = s.length()-1; i >= 0; i--) {
            if (s[i] != ' ') {
                beh = now = i;
                while (now >= 0 && s[now] != ' ') {
                    now--;
                }
                int thisLen = beh - now;
                string thisWord = s.substr(now+1, thisLen);
                if (res.length() == 0) {
                    res.append(thisWord);
                }else{
                    res.append(" ");
                    res.append(thisWord);
                }
                i = now + 1;
            }
        }
        s = res;
    }
};
