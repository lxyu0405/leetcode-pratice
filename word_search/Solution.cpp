#include <vector>
#include <string>
#include <iostream>

using namespace std;

class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        vector<vector<bool>> used(board.size(), vector<bool>(board.front().size(), false));
        for (int i = 0; i < board.size(); i++) {
            for (int j = 0; j < board.front().size(); j++) {
                if (board[i][j] == word[0]) {
                    if (word.length() == 1) {
                        return true;
                    }
                    // backtracking search
                    used[i][j] = true;
                    if (findSequence(board, used, word.substr(1), i, j)) {
                        return true;
                    }
                    used[i][j] = false;
                }
            }
        }
        return false;
    }
private:
    bool findSequence(vector<vector<char>>& board, vector<vector<bool>>& used, string word, int row, int col){
        // 1 - above, 2 - right, 3 - below, 4 - left
        for (int i = 1; i <= 4; i++) {
            int nextRow = row, nextCol = col;
            switch (i) {
                case 1:
                    nextRow--;
                    break;
                case 2:
                    nextCol++;
                    break;
                case 3:
                    nextRow++;
                    break;
                case 4:
                    nextCol--;
                    break;
            }
            if (validPos(board, nextRow, nextCol) && !used[nextRow][nextCol] && board[nextRow][nextCol] == word[0]) {
                if (word.length() == 1) {
                    return true;
                }
                used[nextRow][nextCol] = true;
                if (findSequence(board, used, word.substr(1), nextRow, nextCol)) {
                    return true;
                }
                used[nextRow][nextCol] = false;
            }
        }
        return false;
    }
    
    bool validPos(vector<vector<char>>& board, int row, int col){
        return row >= 0 && row < board.size() && col >= 0 && col < board.front().size();
    }
};
