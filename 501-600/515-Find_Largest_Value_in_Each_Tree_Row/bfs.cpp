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
    vector<int> largestValues(TreeNode* root) {
        // Init
        vector<int> rows;
        queue<TreeNode*> q({root});

        // BFS
        while (!q.empty()) {
            int _size = q.size();
            int _max = INT_MIN;

            for (int i=0; i<_size; ++i) {
                if (q.front() != nullptr) {
                    _max = max(_max, q.front()->val);
                    q.push(q.front()->left);
                    q.push(q.front()->right);
                }

                q.pop();
            }

            rows.emplace_back(_max);
        }

        rows.pop_back();

        return rows;
    }
};

