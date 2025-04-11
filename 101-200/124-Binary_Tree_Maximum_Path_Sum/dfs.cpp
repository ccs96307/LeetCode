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
    int DFS(TreeNode* root, int& maxSum) {
        // Base case
        if (!root) {
            return 0;
        }

        int leftSum = max(0, DFS(root->left, maxSum));
        int rightSum = max(0, DFS(root->right, maxSum));

        // Take the max value
        maxSum = max(maxSum, leftSum+rightSum+root->val);

        return max(leftSum, rightSum) + root->val;
    }

    int maxPathSum(TreeNode* root) {
        int maxSum = INT_MIN;
        DFS(root, maxSum);
        return maxSum;
    }
};

