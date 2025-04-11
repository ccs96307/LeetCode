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
    bool isEvenOddTree(TreeNode* root) {
        // Base case
        if (root->val % 2 == 0) {
            return false;
        }

        // Init
        int depth = 0;
        queue<TreeNode*> q({root});

        // Traversal
        while (!q.empty()) {
            depth = (depth + 1) % 2;

            int _size = q.size();
            int last = depth == 1 ? INT_MIN : INT_MAX;

            for (int i=0; i<_size; ++i) {
                TreeNode* node = q.front();
                q.pop();

                if (node == nullptr) {
                    continue;
                }

                if (node->val % 2 != depth) {
                    return false;
                }

                if (depth == 1) {
                    if (node->val <= last) {
                        return false;
                    }

                    last = node->val;
                }
                else {
                    if (node->val >= last) {
                        return false;
                    }

                    last = node->val;
                }

                q.push(node->left);
                q.push(node->right);
            }
        }

        return true;
    }
};

