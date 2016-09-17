#include <iostream>
#include <string>
#include <vector>
#include <cmath>

using namespace std;

int main(){
    vector<int> prices;
    int thisPrice;
    char q;
    while (cin >> thisPrice) {
        prices.push_back(thisPrice);
        if (cin >> q);
    }
    int minPrices = prices[0];
    int maxProfit = 0;
    for (int i = 1; i < prices.size(); i++){
        minPrices = prices[i] < minPrices ? prices[i] : minPrices;
        maxProfit = (prices[i] - minPrices) > maxProfit ? (prices[i] - minPrices) : maxProfit;
    }
    cout << maxProfit << endl;;
    return 0;
}
