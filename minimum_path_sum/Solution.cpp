#include <iostream>
#include <vector>

using namespace std;

#define MIN(A,B) (A < B ? A : B);

class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        const int row = grid.size();
        const int col = grid.front().size();
        for (int i = 1; i < col; i++) {
            grid[0][i] += grid[0][i-1];
        }
        for (int i = 1; i < row; i++) {
            grid[i][0] += grid[i-1][0];
        }
        for (int i = 1; i < row; i++) {
            for (int j = 1; j < col; j++) {
                grid[i][j] += MIN(grid[i-1][j], grid[i][j-1]);
            }
        }
        return grid[row-1][col-1];
    }
};
