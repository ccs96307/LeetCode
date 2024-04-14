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
    void DFS(TreeNode* root, int& sumResult, bool isLeft) {
        // Base case
        if (root == nullptr) {
            return;
        }
        
        if (isLeft && root->left == nullptr && root->right == nullptr) {
            sumResult += root->val;
            return;
        }

        // DFS
        DFS(root->left, sumResult, true);
        DFS(root->right, sumResult, false);
    }

    int sumOfLeftLeaves(TreeNode* root) {
        // Init
        int sumResult = 0;

        // DFS
        DFS(root, sumResult, false);

        return sumResult;
    }
};

