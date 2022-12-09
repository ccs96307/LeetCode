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
    void DFS(TreeNode* root, vector<int>& maxValSeq, vector<int> minValSeq, int& maxDiff) {
        // Base case
        if (!root) {
            return;
        }

        // Update maximum difference
        maxDiff = max(maxDiff, abs(maxValSeq.back()-root->val));
        maxDiff = max(maxDiff, abs(minValSeq.back()-root->val));
        
        // Update sequence
        if (root->val > maxValSeq.back()) {
            maxValSeq.push_back(root->val);
        }
        else {
            maxValSeq.push_back(maxValSeq.back());
        }

        if (root->val < minValSeq.back()) {
            minValSeq.push_back(root->val);
        }
        else {
            minValSeq.push_back(minValSeq.back());
        }

        // DFS
        DFS(root->left, maxValSeq, minValSeq, maxDiff);
        DFS(root->right, maxValSeq, minValSeq, maxDiff);

        // Pop
        maxValSeq.pop_back();
        minValSeq.pop_back();
    }

    int maxAncestorDiff(TreeNode* root) {
        vector<int> maxValSeq({root->val});
        vector<int> minValSeq({root->val});
        int maxDiff = 0;

        DFS(root->left, maxValSeq, minValSeq, maxDiff);
        DFS(root->right, maxValSeq, minValSeq, maxDiff);

        return maxDiff;
    }
};

