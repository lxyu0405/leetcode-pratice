#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        if (nums.size() <= 1) {
            return nums;
        }
        // O(nlgn)
        sort(nums.begin(), nums.end());
        vector<vector<int>> largestSubset(nums.size(), vector<int>());
        // First subset only has one element, the smallest one
        largestSubset[0].push_back(nums[0]);
        int largestIndex = 0;
        // O(n^2)
        for (int i = 1; i < nums.size(); i++) {
            int findLargestSub = -1;
            int largestSubSize = 0;
            // try to find the largest subset to extend
            for (int j = i-1; j >= 0; j--) {
                if ((nums[i] % nums[j] == 0) && largestSubset[j].size() > largestSubSize) {
                    findLargestSub = j;
                    largestSubSize = largestSubset[j].size();
                }
            }
            // can't find any subset to extend
            if (findLargestSub == -1) {
                largestSubset[i].push_back(nums[i]);
            }else{
            // extend the largest subset
                largestSubset[i] = largestSubset[findLargestSub];
                largestSubset[i].push_back(nums[i]);
            }
            
            // record the largest subset
            largestIndex = largestSubset[largestIndex].size() > largestSubset[i].size() ? largestIndex : i;
        }
        return largestSubset[largestIndex];
    }
};
