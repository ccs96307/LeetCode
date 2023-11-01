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
        unordered_map<int, int> num2times;
        map<int, vector<int>> modes;
        queue<TreeNode*> q({root});

        // Counting
        while (!q.empty()) {
            // Base case
            if (q.front() == nullptr) {
                q.pop();
                continue;
            }

            // Record
            ++num2times[q.front()->val];
            modes[num2times[q.front()->val]].emplace_back(q.front()->val);

            // Traversal
            q.push(q.front()->left);
            q.push(q.front()->right);

            // Pop
            q.pop();
        }

        return modes.rbegin()->second;
    }
};

