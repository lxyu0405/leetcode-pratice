#include <vector>
#include <string>
#include <iostream>
#include <stack>

using namespace std;

class Solution {
public:
    vector<string> restoreIpAddresses(string s) {
        vector<string> res;
        if (s.length() < 4) {
            return res;
        }
        ipPart(s, 0, "", 4, res);
        return res;
    }
    
    void ipPart(string ip, int start, string before, int left, vector<string>& res){
        // end
        if (left == 0 && start == ip.length()) {
            res.push_back(before);
        }
        if (left == 0 && start != ip.length()) {
            return;
        }
        
        // Recursion
        if (ip[start] == '0') {
            left == 4 ? ipPart(ip, start+1, "0", left-1, res): ipPart(ip, start+1, before + ".0", left-1, res);
        }else{
            for (int i = start; i < ip.length(); i++) {
                if (isIpPart(ip.substr(start,i-start+1))) {
                    left == 4 ? ipPart(ip, i+1, ip.substr(start, i-start+1), left-1, res) : ipPart(ip, i+1, before + "." + ip.substr(start, i-start+1), left-1, res);
                }
            }
        }
    }
    
    bool isIpPart(string part){
        int thisPart =  atoi(part.c_str());
        return (thisPart > 0 && thisPart < 256) ? true : false;
    }
};

int main(){
    Solution test;
    test.restoreIpAddresses("00100");
    return 0;
}
