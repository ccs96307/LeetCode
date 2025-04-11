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
    int answer = 0;

    pair<int, int> DFS(TreeNode* root) {
        // Base case
        if (root == nullptr) {
            return pair<int, int>({0, 0});
        }

        // DFS
        pair<int, int> leftItem = DFS(root->left);
        pair<int, int> rightItem = DFS(root->right);

        // Check if the average number is equal to the current node value
        int accum = root->val + leftItem.first + rightItem.first;
        int nodeNum = 1 + leftItem.second + rightItem.second;
        int avg = accum / nodeNum;
        if (avg == root->val) {
            ++answer;
        }
        
        return pair<int, int>({accum, nodeNum});
    }

    int averageOfSubtree(TreeNode* root) {
        DFS(root);
        return answer;
    }
};

