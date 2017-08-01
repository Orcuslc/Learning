/**
 * Definition for undirected graph.
 * struct UndirectedGraphNode {
 *     int label;
 *     vector<UndirectedGraphNode *> neighbors;
 *     UndirectedGraphNode(int x) : label(x) {};
 * };
 */
class Solution {
    unordered_map<int, UndirectedGraphNode*> mp;

public:
    UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node) {
        if(!node) return NULL;
        if(mp.find(node->label) == mp.end()) {
            mp[node->label] = new UndirectedGraphNode(node->label);
            for(UndirectedGraphNode* neigh: node->neighbors) {
                mp[node->label]->neighbors.push_back(cloneGraph(neigh));
            }
        }
        return mp[node->label];
    }
};