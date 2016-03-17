/*There two sorted arrays nums1 and nums2 of size m and n respectively.
 Find the median of the two sorted arrays. The overall run time complexity should be O(log (m+n)).
*/

// Brute Force Method, quicksort: O((m+n)lg(m+n)) ~ O(nlgn)
// Merge Method, two pointers: O(m+n)

#include <stdio.h>
#include <vector>
#include <iostream>

using std::vector;

using std::cin;
using std::cout;
using std::endl;

// typedef vector<int>::size_type vInt;

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int k1 = (nums1.size() + nums2.size() + 1) >> 1;
        int k2 = (nums1.size() + nums2.size() + 2) >> 1;
        
        return double(findKth(nums1, 0, nums1.size(), nums2, 0, nums2.size(), k1) + findKth(nums1, 0, nums1.size(), nums2, 0, nums2.size(), k2))/2;
        
    }
    
    int findKth(vector<int>& nums1, int l1, int r1, vector<int>& nums2, int l2, int r2, int k){
        
        int m = r1 - l1;
        int n = r2 - l2;
        // make m <= n always
        if (m > n) {
            return findKth(nums2, l2, r2, nums1, l1, r1, k);
        }
        if (m == 0) {
            return nums2[k-1];
        }
        if (k == 1) {
            return nums1[l1] > nums2[l2] ? nums2[l2] : nums1[l1];
        }
        int i = m < (k >> 1) ? m : (k >> 1);
        int j = k - i;
    
        if (nums1[l1 + i - 1] == nums2[l2 + j - 1]) {
            return nums1[l1 + i - 1];
        }else if (nums1[l1 + i - 1] < nums2[l2 + j - 1]) {
            return findKth(nums1, l1+i, r1, nums2, l2, r2, k-i);
        }else{
            return findKth(nums1, l1, r1, nums2, l2+j, r2, k-j);
        }
    }
    
};

int main(){
    Solution test;
    vector<int> nums1;
    vector<int> nums2;
    
    nums1.push_back(1);
    nums1.push_back(2);
    nums2.push_back(1);
    nums2.push_back(2);

    cout << test.findMedianSortedArrays(nums1, nums2) << endl;
    
    return 0;
}
