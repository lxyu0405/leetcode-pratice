#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int row = matrix.size(), col = matrix.front().size();
        int targetRow = findTargetRow(matrix, target);
        return findVal(matrix[targetRow], target);
    }
private:
    bool findVal(vector<int>& thisRow, int target){
        // binary search value
        int rowStart = 0, rowEnd = thisRow.size() - 1;
        while (rowStart < rowEnd) {
            int thisMid = (rowStart + rowEnd) / 2;
            if (thisRow[thisMid] == target) {
                return true;
            }else if (thisRow[thisMid] < target) {
                rowStart = thisMid + 1;
            }else{
                rowEnd = thisMid - 1;
            }
        }
        return thisRow[rowStart] == target ? true : false;
    }
    int findTargetRow(vector<vector<int>>& matrix, int target){
        // binary search col
        int colStart = 0, colEnd = matrix.size() - 1;
        while (colStart < colEnd) {
            if ((colStart + 1) == colEnd) {
                if (matrix[colEnd][0] <= target) {
                    return colEnd;
                }else{
                    return colStart;
                }
            }
            int thisMid = (colStart + colEnd) / 2;
            if (matrix[thisMid][0] <= target) {
                colStart = thisMid;
            }else{
                colEnd = thisMid - 1;
            }
        }
        return colStart;
    }
};
