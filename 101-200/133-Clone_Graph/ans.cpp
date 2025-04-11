/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    Node* dfs(Node* node, unordered_map<int, Node*>& visited) {
        // Create a new Node
        Node* cloneNode = new Node(node->val);
        
        // Record the node is visited
        visited.insert({node->val, cloneNode});
        
        // Keep finding
        for (Node* neighbor: node->neighbors) {
            if (visited.count(neighbor->val)) {
                cloneNode->neighbors.push_back(visited[neighbor->val]);
            }
            else {
                // DFS
                Node* newCloneNode = dfs(neighbor, visited);
                cloneNode->neighbors.push_back(newCloneNode);
            }
        }
        
        return cloneNode;
    }
    
    Node* cloneGraph(Node* node) {
        // Base case
        if (node == nullptr) return nullptr;
        
        // Init
        unordered_map<int, Node*> visited;
                
        // Clone
        return dfs(node, visited);        
    }
};
