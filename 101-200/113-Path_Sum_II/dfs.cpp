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
    vector<vector<int>> results;
    
    void DFS(TreeNode* root, vector<int>& result, int targetSum, int currSum) {
        currSum += root->val;
        result.push_back(root->val);
        
        if (root->left == nullptr && root->right == nullptr) {
            if (currSum == targetSum) {
                results.push_back(result);
            }            
        }
        
        if (root->left) {
            DFS(root->left, result, targetSum, currSum);
        }
        if (root->right) {
            DFS(root->right, result, targetSum, currSum);
        }
        
        result.pop_back();
    }
    
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {     
        // Base case
        if (root == nullptr) return {};
        
        // Init
        vector<int> v;
        DFS(root, v, targetSum, 0);
        
        return results;
    }
};

