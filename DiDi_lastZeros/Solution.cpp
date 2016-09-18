#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <cmath>

using namespace std;


int main(){
    int n;
    cin >> n;
    int num = 0;
    
    while(n){
        num += n / 5;
        n = n / 5;
    }
    cout << num << endl;
    
    return 0;
}
