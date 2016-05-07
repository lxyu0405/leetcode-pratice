#include <vector>
#include <string>
#include <unordered_map>
#include <queue>
#include <iostream>

using namespace std;

/**
 * Definition for undirected graph.
 */
struct UndirectedGraphNode {
    int label;
    vector<UndirectedGraphNode *> neighbors;
    UndirectedGraphNode(int x) : label(x) {};
};

class Solution {
public:
    UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node) {
        if (node == NULL) {
            return NULL;
        }
        UndirectedGraphNode* thisNode = new UndirectedGraphNode(node->label);
        unordered_map<UndirectedGraphNode*, UndirectedGraphNode*> visited;
        queue<UndirectedGraphNode*> BFSTraversal;
        
        visited[node] = thisNode;
        BFSTraversal.push(node);
        
        while (!BFSTraversal.empty()) {
            UndirectedGraphNode* oldNode = BFSTraversal.front();
            UndirectedGraphNode* newNode = visited[oldNode];
            BFSTraversal.pop();
            for (auto nodeNeigh : oldNode->neighbors) {
                if (visited.count(nodeNeigh)) {
                    newNode->neighbors.push_back(visited[nodeNeigh]);
                }else{
                    UndirectedGraphNode* newNeigh = new UndirectedGraphNode(nodeNeigh->label);
                    newNode->neighbors.push_back(newNeigh);
                    
                    visited[nodeNeigh] = newNeigh;
                    BFSTraversal.push(nodeNeigh);
                }
            }
        }
        return thisNode;
    }
};
