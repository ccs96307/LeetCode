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
    void DFS(int& palindromeNum, TreeNode* root, vector<int>& currPath) {
        ++currPath[root->val];
        int odd = 0;
        
        if (root->left != nullptr) {
            DFS(palindromeNum, root->left, currPath);
        }
        
        if (root->right != nullptr) {
            DFS(palindromeNum, root->right, currPath);
        }
        
        if (root->left == nullptr && root->right == nullptr) {
            // Count odd number
            for (int& n: currPath) {
                odd += n % 2;
            }
            
            if (odd <= 1) {
                ++palindromeNum;
            }
        }
        
        --currPath[root->val];
    }
    
    int pseudoPalindromicPaths (TreeNode* root) {
        int palindromeNum = 0;
        vector<int> v(10, 0);
        
        DFS(palindromeNum, root, v);
        
        return palindromeNum;
    }
};

