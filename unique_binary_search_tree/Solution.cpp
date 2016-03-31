class Solution {
public:
    int numTrees(int n) {
        vector<int> num(n+1,0);
        num[0] = 1, num[1] = 1, num[2] = 2;
        for (int i = 3; i < n+1; i++) {
            for (int j = 1; j < i+1; j++) {
                num[i] += num[j-1] * num[i-j];
            }
        }
        return num[n];
    }
};
