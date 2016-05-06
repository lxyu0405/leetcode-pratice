#include <vector>
#include <utility>
#include <string>
#include <queue>
#include <unordered_map>
#include <iostream>

using namespace std;

typedef pair<int, int> Pair;

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        vector<int> res;
        
        // construct a heap, using priority queue
        auto cmp = [](const Pair& p1, const Pair& p2)->bool{return p1.second < p2.second;};
        priority_queue<Pair, vector<Pair>, decltype(cmp)> freHeap(cmp);
        // calculate frequency
        unordered_map<int, int> calFre;
        for (auto num : nums) {
            calFre[num]++;
        }
        // construct heap
        for (auto it = calFre.begin() ; it != calFre.end(); it++) {
            freHeap.push(make_pair(it->first, it->second));
        }
        for (int i = 0; i < k; i++) {
            res.push_back(freHeap.top().first);
            freHeap.pop();
        }
        
        return res;
    }
};
