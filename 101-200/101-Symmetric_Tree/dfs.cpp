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
    bool DFS(TreeNode* right, TreeNode* left) {
        if (right == nullptr && left == nullptr) {
            return true;
        }
        else if ((right != nullptr && left == nullptr) || (right == nullptr && left != nullptr)){
            return false;
        }
        else if (right->val != left->val){
            return false;
        }

        return DFS(right->right, left->left) && DFS(right->left, left->right);
    }

    bool isSymmetric(TreeNode* root) {
        if (root == nullptr) {
            return true;
        }

        return DFS(root->right, root->left);
    }
};

