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
    void dfs(TreeNode* root, int& n, int& _k, int& k) {
        // Base case
        if (root == nullptr) return;
        
        // Left
        if (root->left != nullptr) {
            dfs(root->left, n, _k, k);
        }
        if (_k == k) return;
        
        // Current node
        n = root->val;
        ++_k;
        if (_k == k) return;
        
        // Right
        if (root->right != nullptr) {
            dfs(root->right, n, _k, k);
        }
        if (_k == k) return;
    }
    
    int kthSmallest(TreeNode* root, int k) {
        // Init
        int n;
        int _k = 0;
        
        // DFS
        dfs(root, n, _k, k);
        
        return n;
    }
};

