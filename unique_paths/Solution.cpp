#include <iostream>
#include <vector>

using std::vector;
using std::cin;
using std::cout;
using std::endl;

class Solution {
public:
    int uniquePaths(int m, int n) {
        if (m <= 0 || n <= 0) {
            return 0;
        }
        
        vector<int> line(n,0);
        vector<vector<int>> map(m,line);
        
        // Initialize first line and first col, all to 1
        for (int i = 0; i < n; i++) {
            map[0][i] = 1;
        }
        for (int i = 0; i < m; i++) {
            map[i][0] = 1;
        }
        
        for (int row = 1; row < m; row++) {
            for (int col = 1; col < n; col++) {
                map[row][col] = map[row-1][col] + map[row][col-1];
            }
        }
        return map[m-1][n-1];
    }
};
