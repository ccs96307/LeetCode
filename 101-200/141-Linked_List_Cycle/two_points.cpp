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
    bool hasCycle(ListNode *head) {
        // Base case
        if (head == nullptr || head->next == nullptr) {
            return false;
        }

        // Init
        ListNode* slow = head;
        ListNode* fast = head;

        // `slow` steps 1, `fast` steps 2 
        while (fast != nullptr && fast->next != nullptr) {
            slow = slow->next;
            fast = fast->next->next;

            if (slow == fast) {
                return true;
            }
        }

        // If reach the nullptr, it means there is no cycle
        return false;
    }
};
