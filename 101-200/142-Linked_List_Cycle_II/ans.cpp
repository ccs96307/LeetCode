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
        unordered_set<ListNode*> set;
        
        while (head != nullptr) {
            if (set.find(head) == set.end()) {
                set.insert(head);
                head = head->next;
            }
            else {
                return head;
            }
        }
        
        return nullptr;
    }
};

