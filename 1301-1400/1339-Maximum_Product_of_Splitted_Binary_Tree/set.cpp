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
    int DFS(TreeNode* root, set<int>& myset) {
        // Base case
        if (!root) {
            return 0;
        }

        int tempLeft = DFS(root->left, myset);
        int tempRight = DFS(root->right, myset);
        myset.insert(tempLeft);
        myset.insert(tempRight);

        return root->val + tempLeft + tempRight;
    }

    int maxProduct(TreeNode* root) {
        // Init
        set<int> myset;
        int total = DFS(root, myset);
        
        // Find the maximum value
        int mod = 1e9 + 7;
        long maxNum = 0;

        for (auto& num: myset) {
            maxNum = max(maxNum, (long)(total-num)*num);
        }

        return maxNum % mod;
    }
};

