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
        // Init
        unordered_map<ListNode*, bool> visited;
        
        // Iteration
        while (head != nullptr) {
            visited[head] = true;
            
            if (visited.count(head->next)) {
                return true;
            }
            
            head = head->next;
        }
        
        return false;
    }
};

