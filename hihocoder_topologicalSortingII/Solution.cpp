#include <iostream>
#include <string>
#include <vector>
#include <numeric>
#include <queue>

using namespace std;

#define MOD 142857;

int main(){
    int N, M, K;
    cin >> N >> M >> K;
    
    vector<int> virusNum(N, 0);
    for (int i = 0; i < K; i++) {
        int thisVirusPos;
        cin >> thisVirusPos;
        virusNum[thisVirusPos-1] = 1;
    }
    
    int totalVirusCnt = 0;
    
    vector<int> inDegree(N, 0);
    vector<vector<int>> adjList(N, vector<int>());
    for (int i = 0; i < M; i++) {
        int u, v;
        cin >> u >> v;
        inDegree[v-1]++;
        adjList[u-1].push_back(v-1);
    }
    
    queue<int> zeroInDegree;
    for (int i = 0; i < inDegree.size(); i++) {
        if (inDegree[i] == 0) {
            zeroInDegree.push(i);
        }
    }
    
    while (!zeroInDegree.empty()) {
        int thisZeroInDegree = zeroInDegree.front();
        zeroInDegree.pop();
        totalVirusCnt = (totalVirusCnt + virusNum[thisZeroInDegree]) % MOD;
        
        for (auto pointTo : adjList[thisZeroInDegree]) {
            virusNum[pointTo] = (virusNum[pointTo] + virusNum[thisZeroInDegree]) % MOD;
            if (--inDegree[pointTo] == 0) {
                zeroInDegree.push(pointTo);
            }
        }
    }
    
    cout << totalVirusCnt % 142857 << endl;
    
    return 0;
}
