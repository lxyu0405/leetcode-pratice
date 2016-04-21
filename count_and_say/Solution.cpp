#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    string countAndSay(int n) {
        string res = "1";
        for (int i = 1; i < n; i++) {
            res = count(res);
            // cout << res << endl;
        }
        return res;
    }
    
    string count(string num){
        string res = "";
        int p1 = 0, p2 = 0;
        while (p2 < num.length()) {
            if (num[p2] != num[p1]) {
                res += (p2 - p1 + '0');
                res += num[p1];
                p1 = p2;
            }
            p2++;
        }
        res += (p2 - p1 + '0');
        res += num[p1];
        return res;
    }
};

int main(){
    Solution test;
    test.countAndSay(10);
    return 0;
}
