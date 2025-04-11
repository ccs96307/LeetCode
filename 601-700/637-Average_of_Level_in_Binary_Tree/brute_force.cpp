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
    vector<double> averageOfLevels(TreeNode* root) {
        // Init
        stack<TreeNode*> st({root});
        stack<TreeNode*> newSt;
        vector<double> results;
        double levelNodeNum = 0;
        double tempValue = 0;
        
        while (!st.empty()) {
            // Get the current node
            TreeNode* currNode = st.top();
            st.pop();
            
            // Push to the new stack
            if (currNode->left != nullptr) {
                newSt.push(currNode->left);
            }
            
            if (currNode->right != nullptr) {
                newSt.push(currNode->right);
            }
                           
            // Sum all the values of the current level
            tempValue += double(currNode->val);
            ++levelNodeNum;
            
            // If this level is empty, start to compute the next level
            if (st.empty()) {
                st.swap(newSt);
                
                tempValue /= levelNodeNum;
                results.push_back(tempValue);
                
                tempValue = 0;
                levelNodeNum = 0;
            }
        }
        
        return results;
    }
};

