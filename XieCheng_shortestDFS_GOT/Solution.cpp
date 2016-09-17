#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <cmath>

using namespace std;

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

void printMatrix(const vector<vector<int>> & matrix){
    for (auto line : matrix) {
        for (auto num : line) {
            cout << num << " ";
        }
        cout << endl;
    }
}

void shortestDFS(vector<bool> &visited, const vector<vector<int>> &adj, int pstart, int length, int &shortestLen){
    bool end = true;
    for (int i = 0; i < visited.size(); i++) {
        if (!visited[i]) {
            end = false;
            visited[i] = true;
            shortestDFS(visited, adj, i, length + adj[pstart][i], shortestLen);
            visited[i] = false;
        }
    }
    if (end && (shortestLen == -1 || length < shortestLen)) {
        shortestLen = length;
    }
    return ;
}


int main(){
    int n;
    cin >> n;
    vector<vector<int>> adjMatrix(n, vector<int>());
    
    vector<string> oneLine;
    string thisLine = "";
    getline(cin, thisLine);
    
    for (int i = 0; i < n; i++) {
        getline(cin, thisLine);
        oneLine = split(thisLine, ',');
        for (int j = 0; j < oneLine.size(); j++) {
            if (oneLine[j].length() > 0) {
                adjMatrix[i].push_back(atoi(oneLine[j].c_str()));
            }
        }
    }
    
    int shortest = -1;
    for (int start = 0; start < n; start++) {
        vector<bool> visited(n, false);
        visited[start] = true;
        shortestDFS(visited, adjMatrix, start, 0, shortest);
    }
    
    cout << shortest << endl;
    
    return 0;
}
