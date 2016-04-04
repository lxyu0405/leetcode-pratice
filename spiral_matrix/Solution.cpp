#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> res;
        if (matrix.size() == 0) {
            return res;
        }
        spiralOrderCore(matrix, res);
        return res;
    }
    void spiralOrderCore(vector<vector<int>>& matrix, vector<int>& res){
        if (matrix.size() == 0) {
            return;
        }
        int row = matrix.size();
        int col = matrix[0].size();
        // First row
        for (int i = 0; i < col; i++) {
            res.push_back(matrix[0][i]);
        }
        // Last col
        for (int i = 1; i < row; i++) {
            res.push_back(matrix[i][col-1]);
        }
        // Last row
        for (int i = col-2; i >= 0 && row > 1; i--) {
            res.push_back(matrix[row-1][i]);
        }
        // First col
        for (int i = row-2; i > 0 && col > 1; i--) {
            res.push_back(matrix[i][0]);
        }
        if (row-2 <= 0 || col-2 <= 0) {
            return;
        }else{
            vector<vector<int>> innerMatrix;
            for (int i = 1; i < row-1; i++) {
                vector<int> oneLine;
                for (int j = 1; j < col-1; j++) {
                    oneLine.push_back(matrix[i][j]);
                }
                innerMatrix.push_back(oneLine);
            }
            spiralOrderCore(innerMatrix, res);
        }
    }
};
int main(){
    vector<vector<int>> matrix;
    vector<int> line0;
    line0.push_back(1);
    line0.push_back(2);
    line0.push_back(3);
    matrix.push_back(line0);
    
    vector<int> line1;
    line1.push_back(4);
    line1.push_back(5);
    line1.push_back(6);
    matrix.push_back(line1);
    
    vector<int> line2;
    line2.push_back(7);
    line2.push_back(8);
    line2.push_back(9);
    matrix.push_back(line2);
    
    Solution test;
    vector<int> res = test.spiralOrder(matrix);
    for (int i = 0; i < res.size(); i++) {
        cout << res[i] << " ";
    }
    cout << endl;
    return 0;
}
