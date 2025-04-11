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
    ListNode* swapPairs(ListNode* head) {
        if (head == NULL or head->next == NULL) {
            return head;
        }

        vector<int> v;
        ListNode* currentNode = new ListNode(0, head);

        while (currentNode->next != NULL) {
            v.push_back(currentNode->next->val);
            currentNode->next = currentNode->next->next;
        }

        // swap
        int temp = 0;
        for (int i=0; i<v.size(); i++) {
            if (i % 2 == 0 and i+1 < v.size()) {
                temp = v[i];
                v[i] = v[i+1];
                v[i+1] = temp;
            }
        }

        // Create ans
        ListNode* newHead = new ListNode();
        ListNode* newCurrentNode = new ListNode(0, newHead);

        for (int i=0; i<v.size(); i++) {
            cout << v[i] << endl;
            newCurrentNode->next->val = v[i];
            if (i == v.size()-1) {
                newCurrentNode->next->next = NULL;
            }
            else {
                ListNode* newNode = new ListNode();
                newCurrentNode->next->next = newNode;
                newCurrentNode->next = newCurrentNode->next->next;
            }
        }

        return newHead;
    }
};