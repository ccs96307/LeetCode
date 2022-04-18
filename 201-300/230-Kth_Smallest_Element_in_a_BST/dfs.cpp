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
    void dfs(TreeNode* root, vector<int>& v, int& k) {
        // Base case
        if (root == nullptr) return;
        
        // Left
        if (root->left != nullptr) {
            dfs(root->left, v, k);
        }
        if (v.size() == k) return;
        
        // Current node
        v.push_back(root->val);
        if (v.size() == k) return;
        
        // Right
        if (root->right != nullptr) {
            dfs(root->right, v, k);
        }
        if (v.size() == k) return;
    }
    
    int kthSmallest(TreeNode* root, int k) {
        // Init
        vector<int> v;
        
        // DFS
        dfs(root, v, k);
        
        return v.back();
    }
};

