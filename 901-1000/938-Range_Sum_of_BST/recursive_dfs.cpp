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
    int rangeSumBST(TreeNode* root, int low, int high) {
        // Base case
        if (!root) {
            return 0;
        }

        // Init
        int rangeSum = 0;

        // If the value of root is inclusive [low, high].
        if (root->val >= low && root->val <= high) {
            rangeSum += root->val;
        }

        // Check the left node and right node
        rangeSum += rangeSumBST(root->left, low, high);
        rangeSum += rangeSumBST(root->right, low, high);

        return rangeSum;
    }
};
