#include <iostream>
#include <string>
#include <vector>
#include <queue>

using namespace std;

class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        if (!grid.size()) {
            return 0;
        }
        int islandsCnt = 0;
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid.front().size(); j++) {
                if (grid[i][j] == '1') {
                    traverseDFS(grid, i, j);
                    islandsCnt++;
                }
            }
        }
        return islandsCnt;
    }
    
    void traverseDFS(vector<vector<char>>& grid, int i, int j){
        grid[i][j] = '0';
        if (i > 0 && grid[i-1][j] == '1') {
            traverseDFS(grid, i-1, j);
        }
        if (i + 1 < grid.size() && grid[i+1][j] == '1') {
            traverseDFS(grid, i+1, j);
        }
        if (j > 0 && grid[i][j-1] == '1') {
            traverseDFS(grid, i, j-1);
        }
        if (j + 1 < grid[0].size() && grid[i][j+1] == '1') {
            traverseDFS(grid, i, j+1);
        }
    }
    
    void traverseBFS(vector<vector<char>>& grid, int i, int j){
        queue<vector<int>> q;
        q.push({i,j});
        grid[i][j] = '0';
        
        while (!q.empty()) {
            i = q.front()[0], j = q.front()[1];
            q.pop();
            
            if (i > 0 && grid[i-1][j] == '1') {
                q.push({i-1,j});
                grid[i-1][j] = '0';
            }
            if (j > 0 && grid[i][j-1] == '1') {
                q.push({i,j-1});
                grid[i][j-1] = '0';
            }
            if (i + 1 < grid.size() && grid[i+1][j] == '1') {
                q.push({i+1,j});
                grid[i+1][j] = '0';
            }
            if (j + 1 < grid.front().size() && grid[i][j+1] == '1') {
                q.push({i,j+1});
                grid[i][j+1] = '0';
            }
        }
    }
    
};

