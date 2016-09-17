#include <iostream>
#include <string>
#include <vector>
#include <cmath>

using namespace std;

int main(){
    int target;
    cin >> target;
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    
    int target_index = -1;
    
    int left = 0, right = n-1;
    while (left < right) {
        int mid = (left + right) >> 1;
        if (arr[mid] == target) {
            target_index = mid;
            cout << target_index << endl;
            return 0;
        }else if(target < arr[mid]){
            right = mid - 1;
        }else{
            left = mid + 1;
        }
    }
    
    // left == right
    if (arr[left] == target) {
        target_index = left;
    }else if (target < arr[left]){
        target_index = -1 - left;
    }else{
        target_index = -1 - left - 1;
    }
    cout << target_index << endl;
    return 0;
}
