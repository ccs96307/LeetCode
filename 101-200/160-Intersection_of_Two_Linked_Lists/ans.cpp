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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        // Init
        int ASize = 0;
        int BSize = 0;
        ListNode *a = headA;
        ListNode *b = headB;

        // Count the lengths of headA and headB
        while (a != nullptr) {
            ++ASize;
            a = a->next;
        }
        while (b != nullptr) {
            ++BSize;
            b = b->next;
        }

        // Align the length
        while (ASize > BSize) {
            headA = headA->next;
            --ASize;
        }
        while (BSize > ASize) {
            headB = headB->next;
            --BSize;
        }

        // Start to check the intersection node
        while (headA != nullptr) {
            if (headA == headB) {
                return headA;
            }

            headA = headA->next;
            headB = headB->next;
        }

        return nullptr;
    }
};

