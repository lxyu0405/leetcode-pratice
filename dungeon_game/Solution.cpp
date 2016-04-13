#include <iostream>
#include <vector>

using namespace std;

#define MIN(A,B) (A < B ? A : B);

class Solution {
public:
    int calculateMinimumHP(vector<vector<int>>& dungeon) {
        const int row = dungeon.size();
        const int col = dungeon.front().size();
        
        vector<vector<int>> minHealth(row, vector<int>(col,0));
        
        minHealth[row-1][col-1] = enterMinHealth(dungeon[row-1][col-1], 1);
        for (int i = row - 2; i >= 0; i--) {
            minHealth[i][col-1] = enterMinHealth(dungeon[i][col-1], minHealth[i+1][col-1]);
        }
        for (int i = col - 2; i >= 0; i--) {
            minHealth[row-1][i] = enterMinHealth(dungeon[row-1][i], minHealth[row-1][i+1]);
        }
        
        for (int i = row - 2; i >= 0; i--) {
            for (int j = col - 2; j >= 0; j--) {
                int goRight = enterMinHealth(dungeon[i][j], minHealth[i][j+1]);
                int goDown = enterMinHealth(dungeon[i][j], minHealth[i+1][j]);
                minHealth[i][j] = MIN(goRight, goDown);
            }
        }
        return minHealth[0][0];
    }
    
    int enterMinHealth(int moveCost, int leftHeal){
        return moveCost < leftHeal ? (leftHeal - moveCost) : 1;
    }
};
