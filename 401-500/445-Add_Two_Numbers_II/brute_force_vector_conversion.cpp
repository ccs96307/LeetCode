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
        vector<int> v1;
        vector<int> v2;

        while (l1 != nullptr) {
            v1.emplace_back(l1->val);
            l1 = l1->next;
        }

        while (l2 != nullptr) {
            v2.emplace_back(l2->val);
            l2 = l2->next;
        }

        if (v1.size() < v2.size()) {
            swap(v1, v2);
        }

        int zeroNum = v1.size() - v2.size();

        vector<int> zeros(zeroNum, 0);
        zeros.insert(zeros.end(), v2.begin(), v2.end());

        int carry = 0;
        for (int i=v1.size()-1; i>=0; --i) {
            v1[i] += zeros[i] + carry;
            carry = v1[i] / 10;
            v1[i] %= 10;
        }

        if (carry == 1) {
            v1.insert(v1.begin(), 1);
        }

        // Convert the final vector back to a linked list
        ListNode* dummy = new ListNode();
        ListNode* curr = dummy;
        for (int i=0; i<v1.size(); ++i) {
            curr->next = new ListNode(v1[i]);
            curr = curr->next;
        }
        return dummy->next;
    }
};
