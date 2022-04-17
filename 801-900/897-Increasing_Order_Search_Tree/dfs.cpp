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
    void solve(TreeNode* root, TreeNode*& newTree) {
        // Base case
        if (root == nullptr) return;
        
        // Left
        solve(root->left, newTree);
        
        // Assign
        newTree->right = new TreeNode();
        newTree = newTree->right;
        newTree->val = root->val;
        
        // Right
        solve(root->right, newTree);
    }
    
    TreeNode* increasingBST(TreeNode* root) {
        // Init
        TreeNode* newTree = new TreeNode();
        TreeNode* head = newTree;
        
        // Solve
        solve(root, newTree);
        
        return head->right;
    }
};

