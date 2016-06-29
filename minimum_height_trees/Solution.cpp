#include <vector>
#include <unordered_set>
#include <iostream>

using namespace std;

struct graphNode{
    bool erased;
    unordered_set<int> neighbour;
};

class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<pair<int, int>>& edges) {
        vector<graphNode> graph(n);
        // construct the graph
        for (auto edge : edges) {
            graph[edge.first].neighbour.insert(edge.second);
            graph[edge.first].erased = false;
            graph[edge.second].neighbour.insert(edge.first);
            graph[edge.second].erased = false;
        }
        return getMinHeightTreesRoots(graph);
    }
private:
    vector<int> getMinHeightTreesRoots(vector<graphNode>& graph){
        vector<int> thisLayerLeaves;
        vector<int> onlyOneRes;
        bool findRoots = true;
        for (int i = 0; i < graph.size(); i++) {
            // find leaves
            if ((!graph[i].erased) && graph[i].neighbour.size() == 1) {
                thisLayerLeaves.push_back(i);
            }
            // find inner nodes
            if ((!graph[i].erased) && graph[i].neighbour.size() > 1) {
                findRoots = false;
            }
            // find the last one node
            if ((!graph[i].erased) && graph[i].neighbour.size() == 0) {
                onlyOneRes.push_back(i);
                return onlyOneRes;
            }
        }
        // if all leaves, return the result
        if (findRoots) {
            return thisLayerLeaves;
        }
        // drop the outmost layer nodes
        for (auto leaf : thisLayerLeaves) {
            int hisNeigh = *graph[leaf].neighbour.begin();
            graph[hisNeigh].neighbour.erase(leaf);
            graph[leaf].neighbour.clear();
            graph[leaf].erased = true;
        }
        // drop recursively
        return getMinHeightTreesRoots(graph);
    }
    
};

