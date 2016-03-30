#include <iostream>
#include <vector>
#include <algorithm>

using std::min;
using std::vector;
using std::cin;
using std::cout;
using std::endl;

class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        if (triangle.size() <= 0) {
            return -1;
        }
        vector<vector<int>> nthMin(triangle);
        
        for (int i = triangle.size()-2; i >= 0; i--) {
            vector<int> thisLine = triangle[i];
            for (int j = 0; j < thisLine.size(); j++) {
                nthMin[i][j] += min(nthMin[i+1][j],nthMin[i+1][j+1]);
            }
        }
        
        return nthMin[0][0];
    }
};
