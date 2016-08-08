#include <iostream>
#include <vector>
#include <unordered_set>
#include <queue>

using namespace std;

const int INF = 999999;

/*
 input, 6 (vertex number) 9 (Edges)
 6 9
 1 2 1
 1 3 12
 2 3 9
 2 4 3
 3 5 5
 4 3 4
 4 5 13
 4 6 15
 5 6 4
 */

struct CrossNode{
    int location;
    int distance;
    CrossNode(int loc, int dis){
        location = loc;
        distance = dis;
    }
};

struct ComparaCrossDis{
    bool operator() (const CrossNode &crossNode1, const CrossNode &crossNode2) const{
        return crossNode1.distance > crossNode2.distance;
    }
};

// get disMartix
vector<vector<int>> initialize();
// print result
void printMatrix(vector<vector<int>> &matrix);
// print line vector
void printVector(vector<int> &line);
// Dijkstra Algorithm
vector<int> Dijkstra(vector<vector<int>> &sparseMatrix, int from);
// Dijkstra Algorithm optimized with a priority queue
vector<int> DijkstraPriorityQueueOptimized(vector<vector<int>> &sparseMatrix, int from);

vector<vector<int>> initialize(){
    int N, M;
    cin >> N >> M;
    vector<vector<int>> matrix(N, vector<int>(N, INF));
    for (int i = 0; i < N; i++) {
        matrix[i][i] = 0;
    }
    for (int i = 0; i < M; i++) {
        int from, to, weight;
        cin >> from >> to >> weight;
        matrix[from-1][to-1] = weight;
    }
    return matrix;
}

void printMatrix(vector<vector<int>> &matrix){
    for (auto line : matrix) {
        for (auto num : line) {
            cout << num << "\t";
        }
        cout << endl;
    }
}

void printVector(vector<int> &line){
    for (auto num : line) {
        cout << num << "\t";
    }
    cout << endl;
}

vector<int> DijkstraPriorityQueueOptimized(vector<vector<int>> &sparseMatrix, int from){
    vector<vector<int>> matrix(sparseMatrix);
    int size = matrix.size();
    
    vector<bool> visited(size, false);
    visited[from] = true;
    
    // construct the priority_queue
    priority_queue<CrossNode, vector<CrossNode>, ComparaCrossDis> candidates;
    for (int i = 0; i < size; i++) {
        if (i == from || sparseMatrix[from][i] == INF) {
            continue;
        }
        CrossNode thisCandidate(i, sparseMatrix[from][i]);
        candidates.push(thisCandidate);
    }
    
    while (!candidates.empty()) {
        int minInd = candidates.top().location;
        int minDis = candidates.top().distance;
        candidates.pop();
        if (visited[minInd]) {
            continue;
        }
        // loose the distance between from and other points that minInd is the mid
        for (int j = 0; j < size; j++) {
            if (matrix[minInd][j] == INF) {
                continue;
            }
            if (matrix[from][j] > matrix[from][minInd] + matrix[minInd][j]) {
                matrix[from][j] = matrix[from][minInd] + matrix[minInd][j];
                CrossNode newCandidate(j, matrix[from][minInd] + matrix[minInd][j]);
                candidates.push(newCandidate);
            }
        }
        visited[minInd] = true;
    }
    
    return matrix[from];
}


// return shortest distances from One point
vector<int> Dijkstra(vector<vector<int>> &sparseMatrix, int from){
    vector<vector<int>> matrix(sparseMatrix);
    
    int size = matrix.size();
    
    vector<bool> visited(size, false);
    visited[from] = true;
    // find the nearest point
    for (int i = 0; i < size; i++) {
        int minDis = INF;
        int minInd = -1;
        
        // find the nearest point that not visited yet
        for (int j = 0; j < size; j++) {
            if (!visited[j] && matrix[from][j] < minDis) {
                minDis = matrix[from][j];
                minInd = j;
            }
        }
        if (minInd == -1) {
            break;
        }
        // mark minInd as visited
        visited[minInd] = true;
        
        // loose the distance between from and other points that minInd is the mid
        for (int j = 0; j < size; j++) {
            if (matrix[minInd][j] == INF) {
                continue;
            }
            if (matrix[from][j] > matrix[from][minInd] + matrix[minInd][j]) {
                matrix[from][j] = matrix[from][minInd] + matrix[minInd][j];
            }
        }
    }
    
    return matrix[from];
}


int main(){
    vector<vector<int>> matrix = initialize();
    vector<int> shortestDis = DijkstraPriorityQueueOptimized(matrix, 0);
    printVector(shortestDis);
    return 0;
}
