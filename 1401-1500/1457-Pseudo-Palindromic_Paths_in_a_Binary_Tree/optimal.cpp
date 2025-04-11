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
private:
    int results = 0;

public:
    bool isPalindromic(unordered_map<int, int>& val2num) {
        int odd = 0;
        for (auto& it: val2num) {
            if (it.second == 0) {
                continue;
            }
            if (it.second % 2 == 1) {
                ++odd;
                if (odd > 1) {
                    return 0;
                }
            }
        }

        return 1;
    }

    void DFS(TreeNode* node, unordered_map<int, int>& val2num) {
        ++val2num[node->val];
        
        // If leaf
        if (node->left == nullptr && node->right == nullptr) {
            results += isPalindromic(val2num);
            --val2num[node->val];
            return;
        }

        // Left
        if (node->left != nullptr) {
            DFS(node->left, val2num);
        }

        // Right
        if (node->right != nullptr) {
            DFS(node->right, val2num);
        }

        --val2num[node->val];
    }

    int pseudoPalindromicPaths (TreeNode* root) {
        // Init
        unordered_map<int, int> val2num;

        // DFS
        DFS(root, val2num);

        return results;
    }
};

