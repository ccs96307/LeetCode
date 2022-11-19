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
    void inorderVisit(vector<int>& results, TreeNode* root) {
        if (root) {
            inorderVisit(results, root->left);
            results.push_back(root->val);
            inorderVisit(results, root->right);
        }
    }
    
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> results;
        inorderVisit(results, root);
        
        return results;
    }
};

