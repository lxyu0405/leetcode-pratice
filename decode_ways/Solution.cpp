#include <vector>
#include <string>
#include <iostream>

using namespace std;

class Solution {
public:
    int numDecodings(string s) {
        if (s.length() < 2) {
            return decodeable(s);
        }
        vector<int> decodeWays(s.length()+1, 0);
        decodeWays[0] = 1;
        decodeWays[1] = decodeable(s.substr(0,1)) ? 1 : 0;
        for (int i = 2; i <= s.length(); i++) {
            bool cannotDecode = true;
            if (decodeable(s.substr(i-1,1))) {
                decodeWays[i] = decodeWays[i-1];
                cannotDecode = false;
            }
            if (decodeable(s.substr(i-2,2))) {
                decodeWays[i] += decodeWays[i-2];
                cannotDecode = false;
            }
            if (cannotDecode) {
                return 0;
            }
        }
        return decodeWays[s.length()];
    }
private:
    bool decodeable(string s){
        if (s.length() == 1 && s[0] >= '1' && s[0] <= '9') {
            return true;
        }
        if (s.length() == 2 && atoi(s.c_str()) <= 26 && atoi(s.c_str()) >= 10) {
            return true;
        }
        return false;
    }
};
