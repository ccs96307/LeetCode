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
        // Init
        ListNode* currentNode = new ListNode(0, head);

        // Prevatation
        if (head == NULL) return head;

        // Find
        while (currentNode->next->next != NULL) {
            if (currentNode->next->val == currentNode->next->next->val) {
                currentNode->next->next = currentNode->next->next->next;
            }
            else {
                currentNode->next = currentNode->next->next;
            }
        }

        return head;
    }
};
