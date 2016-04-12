#include <iostream>
#include <vector>
#include <string>

using namespace std;

struct Rule{
    unsigned int ip;
    bool allow;
    int mask;
    Rule(): allow(false), ip(0), mask(-1) {}
};

unsigned int getIP();
bool matchRule(const Rule& rule, const unsigned int thisIP);
bool matchIP(unsigned int ruleIP, unsigned int thisIP, int mask);

unsigned int getIP(){
    unsigned int a, b, c, d;
    unsigned int res = 0;
    char dot;
    cin >> a >> dot >> b >> dot >> c >> dot >> d;
    res |=  (a << 24) | (b << 16) | (c << 8) | d;
    return res;
}

bool matchRule(const Rule& rule, unsigned int thisIP){
    if (rule.mask == -1) {
        return rule.ip == thisIP;
    }else{
        return matchIP(rule.ip, thisIP, rule.mask);
    }
}

bool matchIP(unsigned int ruleIP, unsigned int thisIP, int mask){
    if (mask == 0) {
        return true;
    }
    if (!((ruleIP >> (32-mask)) ^ (thisIP >> (32-mask)))) {
        return true;
    }
    return false;
}


int main(){
    vector<string> res;
    int N = 0, M = 0;
    cin >> N >> M;
    vector<Rule> rules;
    for (int i = 0; i < N; i++) {
        Rule newRule;
        string type;
        cin >> type;
        newRule.allow = (type == "allow");
        newRule.ip = getIP();
        
        char t;
        cin >> t;
        if (t == '/') {
            cin >> newRule.mask;
        }else{
            cin.putback(t);
        }
        rules.push_back(newRule);
    }
    for (int i = 0; i < M; i++) {
        unsigned int thisIP = getIP();
        bool isFind = false;
        for (auto rule: rules) {
            if (matchRule(rule, thisIP)) {
                isFind = true;
                if (rule.allow) {
                    res.push_back("YES");
                    break;
                }else{
                    res.push_back("NO");
                    break;
                }
            }
        }
        if (!isFind) {
            res.push_back("YES");
        }
    }
    for (auto re: res) {
        cout << re << endl;
    }
    return 0;
}


