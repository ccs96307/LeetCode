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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        vector<int> v;

        // Read all list
        for (int i=0; i<lists.size(); i++) {
            ListNode* readNode = new ListNode(0, lists[i]);

            while (readNode->next != NULL) {
                v.push_back(readNode->next->val);
                readNode->next = readNode->next->next;
            }
        }

        // Sort
        sort(v.begin(), v.end());

        // Create
        ListNode* head = new ListNode();
        head->val = -1;
        ListNode* currentNode = new ListNode(0, head);

        for (int i=0; i<v.size(); i++) {
            ListNode* newNode = new ListNode();
            currentNode->next->val = v[i];

            if (i != v.size()-1) {
                ListNode* head = new ListNode();
                currentNode->next->next = newNode;
                currentNode->next = currentNode->next->next;
            }
            else {
                currentNode->next->next = NULL;
            }
        }

        cout << head->val << endl;

        // Excepted
        if (head->val == -1 and head->next == NULL) {
            return NULL;
        }

        return head;
    }
};