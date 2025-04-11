/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        // Init
        ListNode* slow = head;
        ListNode* fast = head;
        ListNode* alias = head;

        // Traversal
        while (fast != nullptr && fast->next != nullptr) {
            // Step
            slow = slow->next;
            fast = fast->next->next;

            // If match
            if (slow == fast) {
                while (alias != slow) {
                    alias = alias->next;
                    slow = slow->next;
                }

                return slow;
            }
        }

        return nullptr;
    }
};

