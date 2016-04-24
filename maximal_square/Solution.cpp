#include <vector>
#include <string>
#include <iostream>

using namespace std;

class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        if (matrix.size() == 0) {
            return 0;
        }
        int res = 0;
        int row = matrix.size(), col = matrix.front().size();
        vector<vector<int>> maxSquare(row, vector<int> (col, 0));
        for (int i = 0; i < row; i++) {
            maxSquare[i][0] = matrix[i][0] - '0';
            res = maxSquare[i][0] > res ? maxSquare[i][0] : res;
        }
        for (int i = 0; i < col; i++) {
            maxSquare[0][i] = matrix[0][i] - '0';
            res = maxSquare[0][i] > res ? maxSquare[0][i] : res;
        }
        for (int i = 1; i < row; i++) {
            for (int j = 1; j < col; j++) {
                if (matrix[i][j] == '1') {
                    maxSquare[i][j] = min(maxSquare[i-1][j-1], min(maxSquare[i-1][j], maxSquare[i][j-1])) + 1;
                    res = maxSquare[i][j] > res ? maxSquare[i][j] : res;
                }
            }
        }
        return res;
    }
    
    int min(int a, int b){
        return a < b ? a : b;
    }
};
