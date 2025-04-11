/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:    
    Node* copyRandomList(Node* head) {
        // Base case
        if (head == nullptr) return nullptr;
        
        // Init
        Node* curr = new Node(head->val);
        Node* result = new Node(0, curr);
        unordered_map<Node*, Node*> map({{head, result->next}});
        
        // Traversal
        while (head != nullptr) {
            // Next part
            if (head->next == nullptr) {
                curr->next = nullptr;
            }
            else if (map.count(head->next)) {
                curr->next = map[head->next];
            }
            else {
                curr->next = new Node(head->next->val);
                map[head->next] = curr->next;
            }
            
            // Random part
            if (head->random == nullptr) {
                curr->random = nullptr;
            }
            else if (map.count(head->random)) {
                curr->random = map[head->random];
            }
            else {
                curr->random = new Node(head->random->val);
                map[head->random] = curr->random;
            }
            
            // Step
            head = head->next;
            curr = curr->next;
        }
                
        return result->next;
    }
};

