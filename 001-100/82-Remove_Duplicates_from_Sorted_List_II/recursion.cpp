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
    ListNode* deleteDuplicates(ListNode* head) {
        // Base case
        if (head == nullptr || head->next == nullptr) {
            return head;
        }
        
        // Init
        int currVal = head->val;
        ListNode* currNode = head->next;
        
        // Recursion
        if (currNode->val != currVal) {
            head->next = deleteDuplicates(currNode);
            return head;
        }
        else {
            while (currNode != nullptr && currNode->val == currVal) {
                currNode = currNode->next;                
            }
            
            return deleteDuplicates(currNode);
        }        
    }
};

