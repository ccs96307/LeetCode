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
    int minDiffInBST(TreeNode* root) {
        // Init
        int minDiff = 100000;
        queue<TreeNode*> q({root});
        vector<int> v;

        // Traversal
        while (!q.empty()) {
            int _size = q.size();
            int tempDiff = 1;

            for (int i=0; i<_size; ++i) {
                if (q.front() != nullptr) {
                    v.emplace_back(q.front()->val);
                    q.push(q.front()->left);
                    q.push(q.front()->right);
                }
                q.pop();
            }
        }

        sort(v.begin(), v.end());
        for (int i=0; i<v.size()-1; ++i) {
            minDiff = min(minDiff, abs(v[i]-v[i+1]));
        }

        return minDiff;
    }
};


