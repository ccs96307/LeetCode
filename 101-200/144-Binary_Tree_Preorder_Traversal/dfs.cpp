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
    void dfs(TreeNode* root, vector<int>& v) {
        // Base case
        if (root == nullptr) {
            return;
        }

        v.emplace_back(root->val);
        dfs(root->left, v);
        dfs(root->right, v);
    }

    vector<int> preorderTraversal(TreeNode* root) {
        // Init
        vector<int> v;

        // DFS
        dfs(root, v);

        return v;
    }
};

