#include <string>
using namespace std;

class Solution {
public:
    string reverseString(string s) {
        string res = "";
        for (auto c : s ) {
            res = c + res;
        }
        return res;
    }
};
