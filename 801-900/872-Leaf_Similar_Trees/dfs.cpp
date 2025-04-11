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
    void DFS(TreeNode* root, vector<int>& leaves) {
        // Base case
        if (!root) {
            return;
        }
        
        // If the root is a leaf
        if (!root->left && !root->right) {
            leaves.emplace_back(root->val);
        }

        // DFS
        DFS(root->left, leaves);
        DFS(root->right, leaves);
    }

    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        vector<int> leaves1;
        vector<int> leaves2;

        DFS(root1, leaves1);
        DFS(root2, leaves2);

        return leaves1 == leaves2;
    }
};

