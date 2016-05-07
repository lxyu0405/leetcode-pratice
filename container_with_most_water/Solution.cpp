#include <vector>
#include <iostream>

using namespace std;

#define MIN(A,B) (A < B ? A : B);

class Solution {
public:
    int maxArea(vector<int>& height) {
        if (height.size() < 2) {
            return 0;
        }
        int res = 0;
        int left = 0, right = height.size()-1;
        while (left < right) {
            int thisArea = min(height[left],height[right]) * (right - left);
            res = thisArea > res ? thisArea : res;
            if (height[left] < height[right]) {
                left++;
            }else if (height[left] > height[right]) {
                right--;
            }else {
                // equal
                left++, right--;
            }
        }
        return res;
    }
};
