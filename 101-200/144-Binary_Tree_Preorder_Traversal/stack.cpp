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
    vector<int> preorderTraversal(TreeNode* root) {
        // Init
        vector<int> v;
        stack<TreeNode*> st({root});

        // Stacking
        while (!st.empty()) {
            TreeNode* node = st.top();
            st.pop();

            if (!node) {
                continue;
            }

            v.emplace_back(node->val);
            st.push(node->right);
            st.push(node->left);
        }

        return v;
    }
};

