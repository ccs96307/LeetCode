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
    void DFS(TreeNode* root, int currMax, int currMin, int& maxDiff) {
        // Base case
        if (!root) {
            return;
        }

        // Update maximum difference
        maxDiff = max(maxDiff, abs(currMax-root->val));
        maxDiff = max(maxDiff, abs(currMin-root->val));
        
        // Update sequence
        currMax = max(root->val, currMax);
        currMin = min(root->val, currMin);

        // DFS
        DFS(root->left, currMax, currMin, maxDiff);
        DFS(root->right, currMax, currMin, maxDiff);
    }

    int maxAncestorDiff(TreeNode* root) {
        int maxDiff = 0;

        DFS(root->left, root->val, root->val, maxDiff);
        DFS(root->right, root->val, root->val, maxDiff);

        return maxDiff;
    }
};

