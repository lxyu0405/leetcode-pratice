// 1    2   3   4   5       6       7       8       9       10  11  12  13  14  15  16
// win  win win -   1->4    2->4    3->4    -       1->8    win win -   win win win -
class Solution {
public:
    bool canWinNim(int n) {
        if(n % 4 == 0){
            return false;
        }
        return true;
    }
};