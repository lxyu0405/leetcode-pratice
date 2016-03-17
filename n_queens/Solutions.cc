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
    vector<vector<string>> solveNQueens(int n) {
        string line(n,'.');
        vector<string> chess(n,line);
        vector<vector<string>> res;
        
        solve(res, chess, 0, n);
        
        return res;
    }
    
    void solve(vector<vector<string>>& allRes, vector<string>& chess, int row, int& n){
        for (int i = 0; i < n; i++) {
            if (isSafe(chess, row, i, n)){
                chess[row][i] = 'Q';
                if (row == n-1) {
                    allRes.push_back(chess);
                }else{
                    solve(allRes, chess, row+1, n);
                }
                chess[row][i] = '.';
            }
        }
    }
    
    
    bool isSafe(vector<string>& chess, int r, int c, int n){
        // No need to check row, the queen is put row by row.
        /*for (int i = 0; i < n; i++) {
            if (chess[r][i] == 'Q') {
                return false;
            }
        }*/
        // check col
        for (int i = 0; i <= r; i++) {
            if (chess[i][c] == 'Q') {
                return false;
            }
        }
        // check 45。135。
        // No need to check positions below. The queen is put row by row.
        for (int i = r-1, j = c-1; i >= 0 && j >= 0; i--, j--) {
            if (chess[i][j] == 'Q') {
                return false;
            }
        }
        for (int i = r-1, j = c+1; i >= 0 && j < n; i--, j++) {
            if (chess[i][j] == 'Q') {
                return false;
            }
        }
        
        return true;
    }
    
    void printNQueens(vector<vector<string>>& chessboard){
        for (int i = 0; i < chessboard.size(); i++) {
            for (int j = 0; j < chessboard[i].size(); j++) {
                cout << chessboard[i][j] << endl;
            }
            cout << "== solution ==" << endl;
        }
    }
};

int main(){
    Solution test;
    
    vector<vector<string>> res(test.solveNQueens(8));
    
    test.printNQueens(res);
    
}
