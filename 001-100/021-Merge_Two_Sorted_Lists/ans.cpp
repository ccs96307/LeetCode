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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        // Init
        ListNode* currentNode_1 = new ListNode();
        ListNode* currentNode_2 = new ListNode();
        ListNode* head = new ListNode();
        ListNode* current = new ListNode();

        // Point
        currentNode_1->next = l1;
        currentNode_2->next = l2;
        current->next = head;

        // Merge the bigger one
        while (currentNode_1->next != NULL && currentNode_2->next != NULL) {
            if (currentNode_1->next->val <= currentNode_2->next->val) {
                current->next->next = currentNode_1->next;
                current->next = current->next->next;
                currentNode_1->next = currentNode_1->next->next;
            }
            else {
                current->next->next = currentNode_2->next;
                current->next = current->next->next;
                currentNode_2->next = currentNode_2->next->next;
            }
        }

        // Merge the remaining link list
        if (currentNode_1->next == NULL) {
            current->next->next = currentNode_2->next;
        }
        else {
            current->next->next = currentNode_1->next;
        }

        return head->next;
    }
};