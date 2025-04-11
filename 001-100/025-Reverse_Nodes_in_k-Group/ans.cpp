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
    ListNode* reverseKGroup(ListNode* head, int k) {
        // Init
        vector<int> nums;
        ListNode* currentNode = new ListNode();
        currentNode->next = head;

        while (currentNode->next != NULL) {
            nums.push_back(currentNode->next->val);
            currentNode->next = currentNode->next->next;
        }

        if (k <= nums.size()) {
            for (int i=0; i<=nums.size(); ++i) {
                if (i % k == k-1 && i+1 <= nums.size()) {
                    reverse(nums.begin()+i+1-k, nums.begin()+i+1);
                }
            }
        }

        // Return
        ListNode* new_head = new ListNode();
        currentNode->next = new_head;

        for (int i=0; i<nums.size(); ++i) {
            cout << nums[i] << endl;

            if (i != nums.size()-1) {
                // New node
                ListNode* new_node = new ListNode();
                currentNode->next->val = nums[i];
                currentNode->next->next = new_node;
                currentNode->next = currentNode->next->next;
            }
            else {
                currentNode->next->val = nums[i];
                currentNode->next->next = NULL;
            }
        }

        return new_head;
    }
};
