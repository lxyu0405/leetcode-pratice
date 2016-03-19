#include <stdio.h>
#include <vector>
#include <string>
#include <iostream>

using std::vector;
using std::string;

using std::cin;
using std::cout;
using std::endl;

class Solution {
public:
    bool solveSudoku(vector<vector<char>>& board) {
        return solveSudoku(board, 0, 0);
    }
    
    bool solveSudoku(vector<vector<char>>& board, int row, int col){
        // all end
        if (row == board.size()) {
            return true;
        }
        // line ends
        if (col == board.size()) {
            return solveSudoku(board, row+1, 0);
        }
        // skip over non-empty box
        if (board[row][col] != '.') {
            return solveSudoku(board, row, col+1);
        }
        // try every nums
        for (int num = 1; num <= 9; num++) {
            if (isValid(board, row, col, num)) {
                board[row][col] = '0' + num;
                if (solveSudoku(board, row, col + 1)){
                    return true;
                }
                board[row][col] = '.';
            }
        }
        return false;
        
    }
    
    bool solveSudoku(vector<string>& string_board, vector<vector<char>>& board){
        for (int i = 0; i < string_board.size(); i++) {
            string line = string_board[i];
            vector<char> char_line;
            for (int j = 0; j < line.length(); j++) {
                char_line.push_back(line[j]);
            }
            board.push_back(char_line);
        }
        return solveSudoku(board);
    }
    
    bool isValid(vector<vector<char>>& board, int row, int col, int num) {
        for (int i = 0; i < board.size(); i++) {
            // check row
            if (board[row][i] - '0' == num ) {
                return false;
            }
            // check col
            if (board[i][col] - '0' == num) {
                return false;
            }
            // check box
            int box_row_begin = row/3 * 3;
            int box_col_begin = col/3 * 3;
            int box_row_det = i/3;
            int box_col_det = i%3;
            if (board[box_row_begin + box_row_det][box_col_begin + box_col_det] - '0' == num) {
                return false;
            }
        }
        return true;
    }
    
    void printBoard(vector<vector<char>>& board){
        for (int i = 0; i < board.size(); i++) {
            for (int j = 0; j < board[i].size(); j++) {
                cout << board[i][j] << "\t";
            }
            cout << endl;
        }
    }
};


int main(){
    
    Solution test;
    
    vector<vector<char>> board;
    vector<string> string_board;
    string_board.push_back("..9748...");
    string_board.push_back("7........");
    string_board.push_back(".2.1.9...");
    string_board.push_back("..7...24.");
    string_board.push_back(".64.1.59.");
    string_board.push_back(".98...3..");
    string_board.push_back("...8.3.2.");
    string_board.push_back("........6");
    string_board.push_back("...2759..");
    
    test.solveSudoku(string_board, board);
    test.printBoard(board);
    
    return 0;
}

