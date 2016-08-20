#include <iostream>
#include <string>
#include <vector>
#include <queue>

using namespace std;

bool canMakeIt(vector<int> &damage, int T, int M, int thisM, int K, int start){
    if (K <= 0) {
        return false;
    }
    if (start >= damage.size() && K > 0) {
        return true;
    }
    int thisDamage = damage[start];
    if (thisDamage >= thisM) {
        return canMakeIt(damage, T, M, M, K-1, start+1);
    }else{
        int nextLife = thisM - thisDamage + T;
        nextLife = nextLife > M ? M : nextLife;
        return canMakeIt(damage, T, M, nextLife, K, start+1);
    }
}

int main(){
    int N, M, K;
    cin >> N >> M >> K;
    vector<int> damage;
    for (int i = 0; i < N; i++) {
        int thisDamage;
        cin >> thisDamage;
        damage.push_back(thisDamage);
    }
    
    int maxT = M;
    if (!canMakeIt(damage, maxT, M, M, K, 0)) {
        cout << -1 << endl;
        return 0;
    }
    
    bool pre = false;
    for (int minT = 1; minT < maxT; minT++) {
        pre = canMakeIt(damage, minT, M, M, K, 0);
        if (pre) {
            cout << minT << endl;
            break;
        }
    }
    
    return 0;
}
