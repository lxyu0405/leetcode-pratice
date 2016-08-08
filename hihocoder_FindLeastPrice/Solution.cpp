#include <vector>
#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

bool findLeastPrice(vector<int> &prices, int thisPos, int nowPrice, int X, int &leastPrices){
    if (nowPrice == X) {
        leastPrices = X;
        return true;
    }
    
    if (nowPrice > X && nowPrice < leastPrices) {
        leastPrices = nowPrice;
        return false;
    }
    
    for (int i = thisPos; i < prices.size(); i++) {
        nowPrice += prices[i];
        if(findLeastPrice(prices, i+1, nowPrice, X, leastPrices)){
            return true;
        }else{
            nowPrice -= prices[i];
        }
    }
    
    return false;
}


int main(){
    int N, X;
    cin >> N >> X;
    
    vector<int> prices;
    int thisPrice;
    for (int i = 0; i < N; i++) {
        cin >> thisPrice;
        prices.push_back(thisPrice);
    }
    
    // sum < X
    int sum = 0;
    for (int n : prices) {
        sum += n;
    }
    if (sum < X) {
        cout << -1 << endl;
        return 0;
    }
    
    // sum >= X
    sort(prices.begin(), prices.end());
    reverse(prices.begin(), prices.end());
    
    int leastPrices = INT16_MAX;
    
    findLeastPrice(prices, 0, 0, X, leastPrices);
    
    cout << leastPrices << endl;
    
    return 0;
}

