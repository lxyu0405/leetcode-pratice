#include <iostream>
#include <vector>
#include <string>

using namespace std;

#define INTMAX 2147483647;

class TrieTree{
    struct Trienode{
        int order;
        bool allow;
        Trienode* childNode[2];
        Trienode(): order(0), allow(false) {
            childNode[0] = childNode[1] = NULL;
        };
        Trienode(int order, bool allow): order(order), allow(allow) {
            childNode[0] = childNode[1] = NULL;
        }
    };
    Trienode *root;
    
public:
    TrieTree(){
        root = new Trienode();
    }
    void add(bool allow, const unsigned int thisIP, int mask, int order){
        Trienode* pres = root;
        for (int i = 0; i < mask; i++) {
            int index = (thisIP >> (31-i)) & 1;
            if (pres->order > 0) {
                return;
            }
            if (!pres->childNode[index]) {
                pres->childNode[index] = new Trienode();
            }
            pres = pres->childNode[index];
        }
        if (pres->order == 0) {
            pres->order = order;
            pres->allow = allow;
        }
    }
    
    // 0 not found, 1 allow, -1 deny
    int search(unsigned int ip){
        Trienode* pres = root;
        if (!pres) {
            return 0;
        }
        int minOrder = 0;
        bool minAllow = false;
        for (int i = 0; i < 32; i++) {
            int index = (ip >> (31-i)) & 1;
            if (pres->order > 0 && ( pres->order < minOrder || minOrder == 0)) {
                minOrder = pres->order;
                minAllow = pres->allow;
            }
            if (!pres->childNode[index]) {
                break;
            }
            pres = pres->childNode[index];
        }
        
        if (!minOrder) {
            return 0;
        }else{
            if (minAllow) {
                return 1;
            }else{
                return -1;
            }
        }
    }
};

unsigned int getIP(){
    unsigned int a, b, c, d;
    unsigned int res = 0;
    char dot;
    cin >> a >> dot >> b >> dot >> c >> dot >> d;
    res |=  (a << 24) | (b << 16) | (c << 8) | d;
    return res;
}

int main(){
    vector<string> res;
    int N = 0, M = 0;
    cin >> N >> M;
    TrieTree* solu = new TrieTree();
    for (int i = 0; i < N; i++) {
        string type;
        cin >> type;
        
        unsigned int ruleIP = getIP();
        
        int mask = 32;
        char t;
        cin >> t;
        if (t == '/') {
            cin >> mask;
        }else{
            cin.putback(t);
        }
        
        solu->add(type == "allow", ruleIP, mask, i+1);
    }
    for (int i = 0; i < M; i++) {
        unsigned int thisIP = getIP();
        int result = solu->search(thisIP);
        if (result == -1) {
            res.push_back("NO");
        }else{
            res.push_back("YES");
        }
    }
    for (auto re: res){
        cout << re << endl;
    }
    return 0;
}

