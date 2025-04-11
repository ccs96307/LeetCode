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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        // Init
        ListNode *currentNode = new ListNode(0, l1);
        
        
        // Traverse
        while (true) {
            // Sum
            currentNode->next->val += l2->val;
            
            // Carry
            if (currentNode->next->val >= 10) {
                currentNode->next->val %= 10;

                if (currentNode->next->next != NULL) {
                    ++currentNode->next->next->val;
                }
                else {
                    ListNode *newNode = new ListNode(1);
                    currentNode->next->next = newNode;
                    currentNode->next->val %= 10;
                }
            }

            // Check
            if (currentNode->next->next == NULL && l2->next == NULL) {
                break;
            }
            else if (currentNode->next->next != NULL && l2->next == NULL) {
                l2->next = new ListNode(0, NULL);
            }
            else if (currentNode->next->next == NULL && l2->next != NULL) {
                currentNode->next->next = l2->next;
                break;
            }
            
            // Forward
            currentNode->next = currentNode->next->next;
            l2 = l2->next;
        }
        
        return l1;
    }
};
