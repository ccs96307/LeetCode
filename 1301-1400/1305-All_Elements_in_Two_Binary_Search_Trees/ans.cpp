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
    void DFS(TreeNode* root, vector<int>& elements) {
        if (root != nullptr) {
            elements.push_back(root->val);
            DFS(root->left, elements);
            DFS(root->right, elements);
        }
    }
    
    vector<int> getAllElements(TreeNode* root1, TreeNode* root2) {
        vector<int> v1;
        vector<int> v2;
        
        DFS(root1, v1);
        DFS(root2, v2);
        
        v1.insert(v1.end(), v2.begin(), v2.end());
        sort(v1.begin(), v1.end());

        return v1;
    }
};

