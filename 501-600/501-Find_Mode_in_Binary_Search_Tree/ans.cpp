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
    vector<int> findMode(TreeNode* root) {
        // Init
        vector<int> modes;
        queue<TreeNode*> q({root});
        unordered_map<int, int> counter;

        // Counting
        while (!q.empty()) {
            ++counter[q.front()->val];
            if (q.front()->left != nullptr) {
                q.push(q.front()->left);
            }

            if (q.front()->right != nullptr) {
                q.push(q.front()->right);
            }

            q.pop();
        }

        // Get the maximum
        int _max = 0;
        for (auto& it: counter) {
            _max = max(_max, it.second);
        }

        for (auto& it: counter) {
            if (it.second == _max) {
                modes.emplace_back(it.first);
            }
        }

        return modes;
    }
};

