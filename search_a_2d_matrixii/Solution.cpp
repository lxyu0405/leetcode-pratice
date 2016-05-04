#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int row = matrix.size();
        int col = matrix.front().size();
        
        int checkRow = 0, checkCol = col - 1;
        while (checkRow < row && checkCol >= 0) {
            if (target == matrix[checkRow][checkCol]) {
                return true;
            }else if (target < matrix[checkRow][checkCol]) {
                checkCol--;
            }else{
                // target > matrix[checkRow][checkCol]
                checkRow++;
            }
        }
        return false;
    }
};

