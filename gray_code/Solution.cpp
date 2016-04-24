class Solution {
public:
    vector<int> grayCode(int n) {
        vector<int> nGray;
        if (n < 1){
            nGray.push_back(0);
            return nGray;
        }
        if (n == 1){
            nGray.push_back(0);
            nGray.push_back(1);
            return nGray;
        }
        vector<int> preNGray = grayCode(n-1);
        for(int i = 0; i < preNGray.size(); i++){
            nGray.push_back(preNGray[i]);
        }
        for(int i = preNGray.size()-1; i >= 0; i--){
            nGray.push_back(preNGray[i] + (1 << (n-1)));
        }
        return nGray;
    }
};
