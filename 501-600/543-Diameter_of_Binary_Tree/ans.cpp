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
    int maxDepth(TreeNode* node, int& res) {
        // Base case
        if (node == nullptr) {
            return 0;
        }

        int left = maxDepth(node->left, res);
        int right = maxDepth(node->right, res);

        // Update
        res = max(res, left + right);

        return max(left, right) + 1;
    }

    int diameterOfBinaryTree(TreeNode* root) {
        int res = 0;
        maxDepth(root, res);

        return res; 
    }
};

