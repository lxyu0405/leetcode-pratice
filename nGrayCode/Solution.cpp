#include <iostream>
#include <vector>
#include <string>
#include <math.h>

using std::vector;
using std::string;
using std::cin;
using std::cout;
using std::endl;

class GrayCode {
public:
    vector<string> getGray(int n) {
        // write code here
        vector<string> nGray(pow(2, n),"");
        if (n == 0) {
            return nGray;
        }
        if (n == 1) {
            nGray[0] = "0";
            nGray[1] = "1";
        }
        vector<string> n_1Gray = getGray(n-1);
        for (int i = 0; i < n_1Gray.size(); i++) {
            nGray[i] = "0" + n_1Gray[i];
            nGray[n_1Gray.size()+i] = "1" + n_1Gray[n_1Gray.size()-i-1];
        }
        return nGray;
    }
};
