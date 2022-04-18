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
    void dfs(TreeNode* root, int& n, int& k) {
        // Base case
        if (root == nullptr) return;
        
        // Left
        if (root->left != nullptr) {
            dfs(root->left, n, k);
        }
        if (k == 0) return;
        
        // Current node
        n = root->val;
        --k;
        if (k == 0) return;
        
        // Right
        if (root->right != nullptr) {
            dfs(root->right, n, k);
        }
        if (k == 0) return;
    }
    
    int kthSmallest(TreeNode* root, int k) {
        // Init
        int n;
        
        // DFS
        dfs(root, n, k);
        
        return n;
    }
};

