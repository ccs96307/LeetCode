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
    ListNode* head = NULL;
    
    Solution(ListNode* head) {
        this->head = head;
    }
    
    int getRandom() {
        int len = 0;
        ListNode* p = this->head;
        
        while (p) {
            p = p->next;
            ++len;  
        }
        
        int selection = rand() % len;
        
        ListNode* ans = this->head;
        
        for (int i=0; i<len; ++i) {
            if (i == selection) break;
            else ans = ans->next;
        }
        
        return ans->val;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(head);
 * int param_1 = obj->getRandom();
 */
