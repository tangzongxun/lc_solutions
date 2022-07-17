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
        auto new_header = head;
        if (head != nullptr && head->next != nullptr) {
            new_header = head->next;
        }
        ListNode* previous = nullptr;
        for (auto p = head; p != nullptr && p->next != nullptr; p = p->next) {
            auto next_1 = p->next;
            auto next_2 = p->next->next;
            p->next = next_2;
            next_1->next = p;
            if (previous != nullptr) {
                previous-> next = next_1;
            }
            previous = p;
        }
        return new_header;
    }
};
