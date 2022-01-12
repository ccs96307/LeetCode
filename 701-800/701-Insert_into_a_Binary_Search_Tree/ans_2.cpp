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
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        // Base case
        if (root == NULL) {
            TreeNode* a = new TreeNode(val);
            return a;
        }
        
        // Init
        TreeNode* node = new TreeNode(0, root, root);
        
        while (true) {
            if (val > node->right->val)
                if (node->right->right != NULL) {
                    node->right = node->right->right;
                }
                else {
                    node->right->right = new TreeNode(val);
                    break;
                }
            else if (val < node->right->val) {
                if (node->right->left != NULL) {
                    node->right = node->right->left;
                }
                else {
                    node->right->left = new TreeNode(val);
                    break;
                }
            }
        }
    
        return root;
    }
};

