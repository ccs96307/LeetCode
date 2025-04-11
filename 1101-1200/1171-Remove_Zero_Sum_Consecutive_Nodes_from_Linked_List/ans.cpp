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
    ListNode* removeZeroSumSublists(ListNode* head) {
        // Init
        ListNode* dummy = new ListNode(0, head);
        unordered_map<int, ListNode*> prefixSumMap;
        int sum = 0;

        // Traversal
        for (ListNode* node = dummy; node != nullptr; node = node->next) {
            sum += node->val;
            prefixSumMap[sum] = node;
            // printf("PrefxSumMap[%d] = %d\n", sum, node->val);
        }

        // Combine
        sum = 0;
        for (ListNode* node = dummy; node != nullptr; node = node->next) {
            sum += node->val;
            node->next = prefixSumMap[sum]->next;
            // printf("sum = %d\n", sum);
        }

        return dummy->next;
    }
};

