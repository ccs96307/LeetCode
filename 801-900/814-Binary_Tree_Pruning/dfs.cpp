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
    TreeNode* pruneTree(TreeNode* root) {
        // Base case
        if (root == nullptr) {
            return nullptr;
        }
                
        root->right = pruneTree(root->right);
        root->left = pruneTree(root->left);
        
        if (root->val == 0) {
            if (root->right == nullptr && root->left == nullptr) {
                return nullptr;
            }
        }
        
        return root;
    }
};

