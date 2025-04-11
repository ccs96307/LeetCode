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
    ListNode* oddEvenList(ListNode* head) {
        // Base case
        if (!head || !head->next) {
            return head;
        }

        // Init
        ListNode* odd = head;
        ListNode* even = head->next;
        ListNode* oddHead = odd;
        ListNode* evenHead = even;

        // Traversal
        while (odd->next && even->next) {
            odd->next = odd->next->next;
            even->next = even->next->next;

            odd = odd->next;
            even = even->next;
        }

        // Concat
        odd->next = evenHead;

        return oddHead;
    }
};

