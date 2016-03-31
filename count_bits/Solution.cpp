class Solution {
public:
    vector<int> countBits(int num) {
        vector<int> cntBits(num+1,0);
        cntBits[0] = 0;
        cntBits[1] = 1;
        for (int i = 2; i <= num; i++){
            if(i & 1){ // Odd Number
                cntBits[i] = cntBits[i>>1] + 1;
            }else{  // Even Number
                cntBits[i] = cntBits[i>>1];
            }
            
        }
        return cntBits;
    }
};
