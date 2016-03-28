#include <iostream>
#include <vector>
#include <string>
#include <math.h>
#include <algorithm>

using std::vector;
using std::string;
using std::cin;
using std::cout;
using std::endl;

class Gift {
public:
    int getValue(vector<int> gifts, int n) {
        // write code here
        std::sort(gifts.begin(), gifts.end());
        int max_head = 0, max_tail = 0;
        int this_head = 0, this_tail = 0;
        for (int i = 0; i < gifts.size(); i++) {
            if (gifts[this_tail] == gifts[this_head]) {
                this_tail++;
            }else{
                int max_length = max_tail - max_head + 1;
                int this_length = this_tail - this_head;
                if (this_length > max_length) {
                    max_tail = this_tail-1;
                    max_head = this_head;
                }
                this_head = this_tail;
                this_tail++;
            }
        }
        int max_length = max_tail - max_head + 1;
        int last_length = this_tail - this_head;
        if (last_length > max_length) {
            max_length = last_length;
            max_tail = this_tail-1;
            max_head = this_head;
        }
        if (max_length > n >> 1) {
            return gifts[max_head];
        }else{
            return 0;
        }
    }
};


 
 int main(int argc, const char * argv[]) {
 int arr[5] = {69946,1250,69946,69946,63110};
 vector<int> gifts(arr,arr+5);
 
 Gift test;
 cout << test.getValue(gifts, 5);
 return 0;
 }
 

