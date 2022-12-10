class Solution {
public:
    long DFS (TreeNode* root, long& totalSum, long& ans) {
        if (!root) {
            return 0;
        }

        long currSum = DFS(root->left, totalSum, ans) + DFS(root->right, totalSum, ans) + root->val;

        ans = max(ans, (totalSum-currSum)*currSum);
        return currSum;
    }

    int maxProduct(TreeNode* root) {
        // Init
        long ans = 0;

        // Find the total sum
        long totalSum = DFS(root, ans, ans);

        // Use total sum to find the answer
        DFS(root, totalSum, ans);
        return ans % long(1e9 + 7);
    }
};

