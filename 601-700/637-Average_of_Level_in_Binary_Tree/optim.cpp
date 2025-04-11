/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<double> averageOfLevels(TreeNode* root) {
        // Init
        queue<TreeNode*> q({root});
        vector<double> results;
        
        while (!q.empty()) {
            int currLevelSize = q.size();
            double sum = 0;
            
            // Compute the current level average value
            for (int i=0; i<currLevelSize; ++i) {
                TreeNode* currNode = q.front();
                q.pop();
                
                sum += currNode->val;
                
                if (currNode->left) {
                    q.push(currNode->left);
                }
                
                if (currNode->right) {
                    q.push(currNode->right);
                }
            }
            
            // Add to the results
            results.push_back(sum/currLevelSize);
        }
        
        return results;
    }
};

