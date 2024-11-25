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
    TreeNode* DFS(vector<int>& nums, int left, int right) {
        // Base case
        if (left > right) {
            return nullptr;
        }

        // Get middle node
        int mid = (left + right) / 2;
        TreeNode* node = new TreeNode(nums[mid]);

        // Get left both sides nodes
        node->left = DFS(nums, left, mid-1);
        node->right = DFS(nums, mid+1, right);

        return node;
    }

    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return DFS(nums, 0, nums.size()-1);
    }
};

