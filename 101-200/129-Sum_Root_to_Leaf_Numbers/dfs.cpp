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
    int DFS(TreeNode* node, int curr) {
        // Base case
        if (node == nullptr) {
            return 0;
        }

        // Sum the node value
        curr = curr * 10 + node->val;
        
        // If the branches are existed
        if (node->left == nullptr && node->right == nullptr) {
            return curr;
        }

        return DFS(node->left, curr) + DFS(node->right, curr);
    }

    int sumNumbers(TreeNode* root) {
        return DFS(root, 0);
    }
};

