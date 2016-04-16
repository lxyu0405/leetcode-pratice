#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> res;
        for (int i = 0; i < nums.size(); i++) {
            vector<int> beginPermu;
            beginPermu.push_back(nums[i]);
            generate(res, removeAt(i, nums), beginPermu);
        }
        return res;
    }
    
    void generate(vector<vector<int>>& res, vector<int> left, vector<int> thisPermu){
        if (left.size() == 0) {
            res.push_back(thisPermu);
            return;
        }
        vector<int> newPermu(thisPermu);
        for (int i = 0; i < left.size(); i++) {
            newPermu.push_back(left[i]);
            generate(res, removeAt(i, left), newPermu);
            newPermu.pop_back();
        }
    }
    vector<int> removeAt(int index, vector<int> array){
        vector<int> removeArray;
        for (int i = 0; i < array.size(); i++) {
            if (i != index) {
                removeArray.push_back(array[i]);
            }
        }
        return removeArray;
    }
    void printPermutations(vector<vector<int>> res){
        for (auto onePermu : res) {
            for (auto num : onePermu) {
                cout << num << " ";
            }
            cout << endl;
        }
    }
};

int main(){
    vector<int> nums;
    nums.push_back(1);
    nums.push_back(2);
    nums.push_back(3);
    
    Solution test;
    test.printPermutations(test.permute(nums));
    return 0;
}
