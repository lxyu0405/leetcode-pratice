#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

const int INF = 999999;

// get disMartix
vector<vector<int>> initialize();
// print result
void printMatrix(vector<vector<int>> &matrix);
// Floyd Algorithm
vector<vector<int>> Floyd(vector<vector<int>> &sparseMatrix);


vector<vector<int>> initialize(){
    vector<vector<int>> matrix{ {0, 2, 6, 4},
                                {INF, 0, 3, INF},
                                {7, INF, 0, 1},
                                {5, INF, 12, 0}};
    
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

// Floyd find shortest route among any two vertexes
vector<vector<int>> Floyd(vector<vector<int>> &sparseMatrix){
    vector<vector<int>> matrix(sparseMatrix);
    int size = matrix.size();
    // start vertex
    for (int start = 0; start < size; start++) {
        // mid vertex
        for (int mid = 0; mid < size; mid++) {
            // end vertex
            for (int end = 0; end < size; end++) {
                if (matrix[start][mid] + matrix[mid][end] < matrix[start][end]) {
                    matrix[start][end] = matrix[start][mid] + matrix[mid][end];
                }
                
            }
        }
    }
    return matrix;
}

int main(){
    vector<vector<int>> matrix = initialize();
    vector<vector<int>> sparseMatrix = Floyd(matrix);
    printMatrix(sparseMatrix);
    return 0;
}
