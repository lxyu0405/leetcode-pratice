#include <vector>
#include <unordered_set>
#include <iostream>
#include <stack>
#include <sstream>

using namespace std;

class Solution {
public:
    bool isValidSerialization(string preorder) {
        vector<string> preorderItems = split(preorder, ',');
        stack<string> checkValid;
        for (string node : preorderItems) {
            checkValid.push(node);
            while (checkValid.size() >= 3) {
                // get top 3 elements in the stack
                string top1 = checkValid.top();     checkValid.pop();
                string top2 = checkValid.top();     checkValid.pop();
                string top3 = checkValid.top();     checkValid.pop();
                
                // check whether it satisfies "number,#,#" pattern
                // if satisfying, cut the leaf
                if (top1 == "#" && top2 == "#" && top3 != "#") {
                    checkValid.push("#");
                }else{
                    checkValid.push(top3);
                    checkValid.push(top2);
                    checkValid.push(top1);
                    break;
                }
            }
        }
        // check whether the whole tree can be cut into none
        return checkValid.size() == 1 && checkValid.top() == "#";
    }
    
private:
    vector<string> split(const string &source, const char &delim){
        stringstream ss(source);
        string token;
        vector<string> res;
        while (getline(ss, token, delim)) {
            if (token.length() > 0) {
                res.push_back(token);
            }
        }
        return res;
    }
    
};
