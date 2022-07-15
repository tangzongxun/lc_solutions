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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if (n <= 0) {
            return head;
        }
        stack<ListNode*> nodes;
        
        for (auto p = head; p != nullptr; p = p->next) {
            nodes.push(p);
        }
        for (int i = 0; i < n; i++) {
            nodes.pop();
        }
        if (nodes.empty()) {
            return head->next;
        }
        nodes.top()->next = nodes.top()->next->next;
        return head;
    }
};
