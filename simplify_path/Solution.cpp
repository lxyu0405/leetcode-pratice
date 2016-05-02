#include <vector>
#include <sstream>
#include <string>
#include <iostream>

using namespace std;

class Solution {
public:
    string simplifyPath(string path) {
        vector<string> dirs = split(path, '/');
        vector<string> validDirs;
        for (auto dir : dirs) {
            if (dir == ".") {
                continue;
            }
            if (dir == "..") {
                if (validDirs.size() > 0) {
                    validDirs.pop_back();
                }
                continue;
            }
            validDirs.push_back(dir);
        }
        string res = "";
        for (auto validDir : validDirs) {
            res += "/" + validDir;
        }
        return res.length() == 0 ? "/" : res;
    }
private:
    vector<string> split(const string &source, const char &delim){
        stringstream ss(source);
        string token;
        vector<string> ans;
        while (getline(ss, token, delim)){
            if (token.length() > 0) {
                ans.push_back(token);
            }
        }
        return ans;
    }
};

int main(){
    Solution test;
    cout << test.simplifyPath("/..");
    return 0;
}
