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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        // Preventation
        if (head->next == NULL) {
            return NULL;
        }
        
        // Init
        ListNode *currentNode = new ListNode(0, head);
        ListNode *removeNode = new ListNode(0, head);
        int length = 0;
        
        // Walk
        while (currentNode->next->next != NULL) {
            ++length;
            if (length <= n) {
                currentNode->next = currentNode->next->next;
            }
            else {
                currentNode->next = currentNode->next->next;
                removeNode->next = removeNode->next->next;
            }
        }

        // If remove node is the first node
        if (n-length == 1) {
            return head->next;
        }
        // Remove other node
        else {
            removeNode->next->next = removeNode->next->next->next;
            return head;
        }
    }
};

