class Solution{
public:
    string getPermutation(int n, int k){
        string res = "";
        vector<int> fac(n, 1);
        vector<int> nums(n,1);
        // get factorial
        for(int i = 1; i < n; i++){
            fac[i] = i * fac[i-1];
            nums[i] += i;
        }
        k--;
        for(int i = n-1; i >= 0; i--){
            int thisNum = k / fac[i];
            k = k % fac[i];
            res += (nums[thisNum] + '0');
            nums.erase(nums.begin() + thisNum);
        }

        return res;
    }
};

