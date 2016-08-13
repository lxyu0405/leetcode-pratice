#include <iostream>
#include <string>
#include <vector>
#include <queue>

using namespace std;
int main(){
    int T;
    cin >> T;
    vector<string> res;
    for (int i = 0; i < T; i++) {
        int N, M;
        cin >> N >> M;
        vector<int> inDegree(N, 0);
        vector<vector<int>> adjList(N, vector<int>());
        int totalCnt = 0;
        for (int j = 0; j < M; j++) {
            int pFrom, pTo;
            cin >> pFrom >> pTo;
            inDegree[pTo-1]++;
            adjList[pFrom-1].push_back(pTo-1);
            totalCnt++;
        }
        
        queue<int> zeroDegree;
        for (int j = 0; j < inDegree.size(); j++) {
            if (inDegree[j] == 0) {
                zeroDegree.push(j);
            }
        }
        
        while (!zeroDegree.empty()) {
            int thisZeroInDegree = zeroDegree.front();
            zeroDegree.pop();
            
            for (auto toPoint : adjList[thisZeroInDegree]) {
                if (--inDegree[toPoint] == 0) {
                    zeroDegree.push(toPoint);
                }
                totalCnt--;
            }
        }
        if (totalCnt == 0) {
            res.push_back("Correct");
        }else{
            res.push_back("Wrong");
        }
    }
    for (auto re : res) {
        cout << re << endl;
    }
    
    return 0;
}
