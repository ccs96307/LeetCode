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
    int DFS(TreeNode* root, int ans) {
        // Base case
        if (!root) return 0;
        
        // Compute the current value
        ans = ans * 2 + root->val;
        
        // The recursive reach the endpoint
        if (!root->left && !root->right) return ans;
        
        // Return
        return DFS(root->left, ans) + DFS(root->right, ans);
    }
    
    int sumRootToLeaf(TreeNode* root) {        
        return DFS(root, 0);
    }
};

