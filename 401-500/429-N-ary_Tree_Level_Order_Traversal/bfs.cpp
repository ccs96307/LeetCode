/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    vector<vector<int>> levelOrder(Node* root) {
        // Base case
        if (root == nullptr) {
            return {};
        }
        
        // Init
        queue<Node*> q({root});
        vector<int> result;
        vector<vector<int>> results;
        
        // Queue
        while (!q.empty()) {
            int qSize = q.size();
            
            // Get the all nodes of current level
            for (int i=0; i<qSize; ++i) {
                
                // Get the current node 
                Node* currNode = q.front();
                q.pop();
                
                // Get the current node value
                result.push_back(currNode->val);
                
                // Push the current node children into queue
                for(auto& child: currNode->children) {
                    q.push(child);                    
                }                
            }
            
            // Save the results
            results.push_back(result);
            result.clear();
        }
        
        return results;        
    }
};



