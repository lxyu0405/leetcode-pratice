#include <stdio.h>
#include <iostream>
#include <vector>

using std::cin;
using std::cout;
using std::endl;

using std::vector;

#define SUDO_SIZE 9

class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        // check every row, col and boxes
        int row_check[SUDO_SIZE][SUDO_SIZE] = {0};
        int col_check[SUDO_SIZE][SUDO_SIZE] = {0};
        int box_check[SUDO_SIZE][SUDO_SIZE] = {0};
    
        for (int i = 0; i < SUDO_SIZE; i++) {
            for (int j = 0; j < SUDO_SIZE; j++) {
                if (board[i][j] != '.') { // not empty
                    int num = board[i][j] - '0' - 1; // get the number value
                    int box_no = (j/3)*3 + i/3;     // construct the box number
                    if (row_check[i][num] || col_check[j][num] || box_check[box_no][num]) {
                        return false;
                    }
                    row_check[i][num] = col_check[j][num] = box_check[box_no][num] = 1;
                }
            }
        }
        return true;
    }
};
