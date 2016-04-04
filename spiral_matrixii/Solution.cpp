#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        if (n <= 0) {
            return vector<vector<int>> ();
        }
        vector<int> line(n,0);
        vector<vector<int>> matrix(n,line);
        int cnt = 0;
        spiralMatrix(matrix, 0, cnt);
        printMatrix(matrix);
        return matrix;
    }
    
private:
    void spiralMatrix(vector<vector<int>>& matrix, int layer, int& cnt){
        int N = matrix.size();
        // first row
        for (int i = layer; i < N-layer; i++) {
            matrix[layer][i] = ++cnt;
        }
        // last col
        for (int i = 1+layer; i < N-layer; i++) {
            matrix[i][N-layer-1] = ++cnt;
        }
        // last row
        for (int i = N-layer-2; i >= layer; i--) {
            matrix[N-layer-1][i] = ++cnt;
        }
        // first col
        for (int i = N-layer-2; i > layer; i--) {
            matrix[i][layer] = ++cnt;
        }
        if (cnt < N*N) {
            spiralMatrix(matrix, ++layer, cnt);
        }else{
            return;
        }
    }
    
    void printMatrix(vector<vector<int>>& matrix){
        for (int i = 0; i < matrix.size(); i++) {
            vector<int> line = matrix[i];
            for (int j = 0; j < line.size(); j++) {
                cout << line[j] << "\t";
            }
            cout << endl;
        }
    }
};

int main(){
    int n;
    cin >> n;
    Solution test;
    test.generateMatrix(n);
    return 0;
}
