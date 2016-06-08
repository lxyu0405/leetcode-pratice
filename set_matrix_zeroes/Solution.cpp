#include <string>
#include <vector>
#include <unordered_set>
#include <iostream>

using namespace std;

class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int row = matrix.size();
        int col = matrix.front().size();
        if (row == 0 || col == 0) {
            return;
        }
        bool set1row = false, set1col = false;
        // check whether the first row needs to be set 0
        for (int i = 0; i < col; i++) {
            if (matrix[0][i] == 0) {
                set1row = true;
                break;
            }
        }
        // check whether the first col needs to be set 0
        for (int i = 0; i < row; i++) {
            if (matrix[i][0] == 0) {
                set1col = true;
                break;
            }
        }
        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                if (matrix[i][j] == 0) {
                    matrix[i][0] = 0;
                    matrix[0][j] = 0;
                }
            }
        }
        setMatrixZeroes(matrix, set1row, set1col);
    }
    
    void setMatrixZeroes(vector<vector<int>>& matrix, bool set1row, bool set1col){
        int row = matrix.size();
        int col = matrix.front().size();
        
        if (set1col || set1row) {
            matrix[0][0] = 0;
        }
        
        for (int i = 1; i < col; i++) {
            // set related col to 0
            if (matrix[0][i] == 0) {
                for (int j = 1; j < row; j++) {
                    matrix[j][i] = 0;
                }
            }
            // set first row to 0
            if (set1row) {
                matrix[0][i] = 0;
            }
        }
        
        for (int i = 1; i < row; i++) {
            // set related row to 0
            if (matrix[i][0] == 0) {
                for (int j = 1; j < col; j++) {
                    matrix[i][j] = 0;
                }
            }
            // set fist col to 0
            if (set1col) {
                matrix[i][0] = 0;
            }
        }
    }
};

int main(){
    vector<vector<int>> matrix;
    matrix.push_back(vector<int>({0,0,0,5}));
    matrix.push_back(vector<int>({4,3,1,4}));
    matrix.push_back(vector<int>({0,1,1,4}));
    matrix.push_back(vector<int>({1,2,1,3}));
    matrix.push_back(vector<int>({0,0,1,1}));
    Solution test;
    test.setZeroes(matrix);
    return 0;
}
