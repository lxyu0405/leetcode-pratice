#include <iostream>
#include <vector>
#include <queue>

using namespace std;

const int INF = 999999;

struct CrossNode{
    int x;
    int y;
    int distance;
    CrossNode(int locx, int locy, int dis){
        x = locx;
        y = locy;
        distance = dis;
    }
};

struct ComparaCrossDis{
    bool operator() (const CrossNode &crossNode1, const CrossNode &crossNode2) const{
        return crossNode1.distance > crossNode2.distance;
    }
};

int getDotPos(int rode, int street, int N, int M){
    if (rode > N || rode <= 0 || street > M || street <= 0) {
        return -1;
    }
    return (rode - 1) * M + street - 1;
}

void DijkstraPriorityQueueOptimized(vector<int> &sparseMatrix, vector<vector<bool>> &accessible, vector<int> &BN, vector<int> &AM, int fromx, int fromy){
    int N = BN.size() + 1;
    int M = AM.size() + 1;
    
    int thisCross = getDotPos(fromx, fromy, N, M);
    vector<bool> visited(sparseMatrix.size(), false);
    visited[thisCross] = true;
    
    // construct the priority_queue
    priority_queue<CrossNode, vector<CrossNode>, ComparaCrossDis> candidates;
    // upCross
    if (getDotPos(fromx-1, fromy, N, M) != -1 && accessible[fromx-2][fromy-1]) {
        CrossNode thisCandidate(fromx-1, fromy, BN[fromx-2]);
        candidates.push(thisCandidate);
    }
    // leftCross
    if (getDotPos(fromx, fromy-1, N, M) != -1 && accessible[fromx-1][fromy-2]) {
        CrossNode thisCandidate(fromx, fromy-1, AM[fromy-2]);
        candidates.push(thisCandidate);
    }
    // rightCross
    if (getDotPos(fromx, fromy+1, N, M) != -1 && accessible[fromx-1][fromy]) {
        CrossNode thisCandidate(fromx, fromy+1, AM[fromy-1]);
        candidates.push(thisCandidate);
    }
    // botCross
    if (getDotPos(fromx+1, fromy, N, M) != -1 && accessible[fromx][fromy-1]) {
        CrossNode thisCandidate(fromx+1, fromy, BN[fromx-1]);
        candidates.push(thisCandidate);
    }

    while (!candidates.empty()) {
        int minIndx = candidates.top().x;
        int minIndy = candidates.top().y;
        int minDis = candidates.top().distance;
        candidates.pop();
        
        int thisCross = getDotPos(minIndx, minIndy, N, M);
        if (visited[thisCross]) {
            continue;
        }
        
        int upCross = getDotPos(minIndx-1, minIndy, N, M);
        int leftCross = getDotPos(minIndx, minIndy-1, N, M);
        int rightCross = getDotPos(minIndx, minIndy+1, N, M);
        int botCross = getDotPos(minIndx+1, minIndy, N, M);
        // upCross
        if (upCross != -1 && accessible[minIndx-2][minIndy-1]) {
            if (sparseMatrix[upCross] > sparseMatrix[thisCross] + BN[minIndx-2]) {
                sparseMatrix[upCross] = sparseMatrix[thisCross] + BN[minIndx-2];
                CrossNode thisCandidate(minIndx-1, minIndy, sparseMatrix[thisCross] + BN[minIndx-2]);
                candidates.push(thisCandidate);
            }
        }
        // leftCross
        if (leftCross != -1 && accessible[minIndx-1][minIndy-2]) {
            if (sparseMatrix[leftCross] > sparseMatrix[thisCross] + AM[minIndy-2]) {
                sparseMatrix[leftCross] = sparseMatrix[thisCross] + AM[minIndy-2];
                CrossNode thisCandidate(minIndx, minIndy-1, sparseMatrix[thisCross] + AM[minIndy-2]);
                candidates.push(thisCandidate);
            }
        }
        // rightCross
        if (rightCross != -1 && accessible[minIndx-1][minIndy]) {
            if (sparseMatrix[rightCross] > sparseMatrix[thisCross] + AM[minIndy-1]) {
                sparseMatrix[rightCross] = sparseMatrix[thisCross] + AM[minIndy-1];
                CrossNode thisCandidate(minIndx, minIndy+1, sparseMatrix[thisCross] + AM[minIndy-1]);
                candidates.push(thisCandidate);
            }
        }
        // botCross
        if (botCross != -1 && accessible[minIndx][minIndy-1]) {
            if (sparseMatrix[botCross] > sparseMatrix[thisCross] + BN[minIndx-1]) {
                sparseMatrix[botCross] = sparseMatrix[thisCross] + BN[minIndx-1];
                CrossNode thisCandidate(minIndx+1, minIndy, sparseMatrix[thisCross] + BN[minIndx-1]);
                candidates.push(thisCandidate);
            }
        }
        
        visited[thisCross] = true;
    }
}

void conSparseMatrix(vector<int> &sparseMatrix, vector<vector<bool>> &accessible, vector<int> &BN, vector<int> &AM, int fromx, int fromy){
    int N = BN.size() + 1;
    int M = AM.size() + 1;
    int thisCross = getDotPos(fromx, fromy, N, M);
    sparseMatrix[thisCross] = 0;
    
    int upCross = getDotPos(fromx-1, fromy, N, M);
    int leftCross = getDotPos(fromx, fromy-1, N, M);
    int rightCross = getDotPos(fromx, fromy+1, N, M);
    int botCross = getDotPos(fromx+1, fromy, N, M);
    if (upCross != -1 && accessible[fromx-2][fromy-1]) {
        sparseMatrix[upCross] = BN[fromx-2];
    }
    if (leftCross != -1 && accessible[fromx-1][fromy-2]) {
        sparseMatrix[leftCross] = AM[fromy-2];
    }
    if (rightCross != -1 && accessible[fromx-1][fromy]) {
        sparseMatrix[rightCross] = AM[fromy-1];
    }
    if (botCross != -1 && accessible[fromx][fromy-1]) {
        sparseMatrix[botCross] = BN[fromx-1];
    }
}


int main(){
    // rode is row, street is col
    // rows = N, cols = M
    int N, M;
    cin >> N >> M;
    vector<int> BN;
    vector<int> AM;
    
    int Bi, Ai;
    for (int i = 0; i < N-1; i++) {
        cin >> Bi;
        BN.push_back(Bi);
    }
    for (int i = 0; i < M-1; i++) {
        cin >> Ai;
        AM.push_back(Ai);
    }
    
    vector<vector<bool>> accessible(N, vector<bool>(M, true));
    
    
    // get K info
    int K;
    cin >> K;
    int thisKx, thisKy;
    for (int i = 0; i < K; i++) {
        cin >> thisKx >> thisKy;
        accessible[thisKx-1][thisKy-1] = false;
    }
    
    // get Q info
    int Q;
    cin >> Q;
    int thisQ1x, thisQ1y, thisQ2x, thisQ2y;
    vector<int> shortestDis(N * M, INF);
    for (int i = 0; i < Q; i++) {
        cin >> thisQ1x >> thisQ1y >> thisQ2x >> thisQ2y;
        
        int thisQTo = getDotPos(thisQ2x, thisQ2y, N, M);
        
        vector<int> shortestDis(N * M, INF);
        conSparseMatrix(shortestDis, accessible, BN, AM, thisQ1x, thisQ1y);
        
        DijkstraPriorityQueueOptimized(shortestDis, accessible, BN, AM, thisQ1x, thisQ1y);
        if (shortestDis[thisQTo] == INF) {
            cout << -1 << endl;
        }else{
            cout << shortestDis[thisQTo] << endl;
        }
    }
    
    
    return 0;
}

