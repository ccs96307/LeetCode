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
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        // Compute the list size
        int size = 0;
        ListNode* sizeNode = head;
        while (sizeNode) {
            ++size;
            sizeNode = sizeNode->next;
        }

        // Distribute the size of k-part
        int kSize = size / k;
        int kRemainder = size % k;
        vector<int> sizeGroup(k, kSize);
        for (int i=0; i<kRemainder; ++i) {
            ++sizeGroup[i];
        }

        // Create list group
        vector<ListNode*> listGroup;
        ListNode* newHead = head;
        for (int currSize: sizeGroup) {
            int _size = 1;
            ListNode* node = newHead;
            while (_size < currSize) {
                node = node->next;
                ++_size;
            }

            if (node) {
                newHead = node->next;
                node->next = nullptr;
            }

            listGroup.emplace_back(head);
            head = newHead;
        }

        return listGroup;
    }
};

