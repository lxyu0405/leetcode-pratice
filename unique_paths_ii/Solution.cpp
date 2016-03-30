#include <iostream>
#include <vector>

using std::vector;
using std::cin;
using std::cout;
using std::endl;

class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        if (obstacleGrid[0][0] == 1) {
            return 0;
        }
        
        vector<vector<int>> map(obstacleGrid);
        int row = obstacleGrid.size();
        int col = obstacleGrid[0].size();
        
        // Initialize the obstacles
        for (int r = 0; r < row; r++) {
            for (int c = 0; c < col; c++) {
                if (obstacleGrid[r][c] == 1) {
                    map[r][c] = -1;
                }
            }
        }
        // Initialize the first row
        bool reachThisRow = true;
        for (int c = 0; c < col; c++) {
            if (map[0][c] == -1) {
                reachThisRow = false;
            }
            if (map[0][c] != -1 && reachThisRow) {
                map[0][c] = 1;
            }else{
                map[0][c] = -1;
            }
            
        }
        // Initialize the first col
        bool reachThisCol = true;
        for (int r = 0; r < row; r++) {
            if (map[r][0] == -1) {
                reachThisCol = false;
            }
            if (map[r][0] != -1 && reachThisCol) {
                map[r][0] = 1;
            }else{
                map[r][0] = -1;
            }
        }
        
        // DP, calculate
        for (int r = 1; r < row; r++) {
            for (int c = 1; c < col; c++) {
                if (map[r][c] != -1) {
                    int above = map[r-1][c];
                    int left = map[r][c-1];
                    if (above != -1 && left != -1) {// Y Y
                        map[r][c] = above + left;
                    }else if (above == -1 && left != -1){// N Y
                        map[r][c] = left;
                    }else if (above != -1 && left == -1){// Y N
                        map[r][c] = above;
                    }else{// N N
                        map[r][c] = -1;
                    }
                }
            }
        }
        if (map[row-1][col-1] == -1) {
            return 0;
        }else{
            return map[row-1][col-1];
        }
    }
};
