/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* sortList(ListNode* head) {
        // Init 
        vector<int> v;
        ListNode* currNode = new ListNode(0, head);
        
        // Get the value
        while (currNode->next != nullptr) {
            v.push_back(currNode->next->val);
            currNode->next = currNode->next->next;
        }
        
        // Turn back to head
        currNode->next = head;
        
        // Sort
        sort(v.begin(), v.end());
        
        // Change the node value
        int i = 0;
        while (currNode->next != nullptr) {
            currNode->next->val = v[i];
            currNode->next = currNode->next->next;
            ++i;
        }
        
        return head;
    }
};

