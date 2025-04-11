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
    string tree2str(TreeNode* root) {        
        // Init
        string s = std::to_string(root->val);

        // If left node is exists.
        if (root->left != nullptr) {
            s += '(';
            s += tree2str(root->left);
            s += ')';
        }
        // If left node does not exist but right does.
        else if (root->right != nullptr) {
            s += "()";
        }

        // If right node is exists.
        if (root->right != nullptr) {
            s += '(';
            s += tree2str(root->right);
            s += ')';
        }

        return s;
    }
};

