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
        // Init
        int _sum = 0;
        stack<TreeNode*> st({root});

        while (!st.empty()) {
            TreeNode* node = st.top();
            st.pop();

            // Base case
            if (node == nullptr) {
                continue;
            }

            if (node->val >= low && node->val <= high) {
                _sum += node->val;
            }

            // If node->val <= low, there is no need to traversal the left side
            if (node->val <= low) {
                st.push(node->right);
            }

            // If node->val >= high, there is no need to traversal the right side
            else if (node->val >= high) {
                st.push(node->left);
            }
            else {
                st.push(node->right);
                st.push(node->left);
            }
        }

        return _sum;
    }
};

