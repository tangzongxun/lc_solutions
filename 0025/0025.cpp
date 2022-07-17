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


vector<vector<ListNode*>> split_list(ListNode *head, int k) {
    vector<vector<ListNode*>> result;
    auto cur = head;
    while (cur != nullptr) {
        int cnt = 0;
        vector<ListNode*> cur_nodes;
        while (cur != nullptr && cnt < k) {
            cur_nodes.push_back(cur);
            cnt++;
            cur = cur->next;
        }
        result.push_back(cur_nodes);
    }
    return result;
}


void reverse(vector<ListNode*> &group, int k) {
    if (group.size() < k) {
        return;
    }
    reverse(group.begin(), group.end());
    for (size_t i = 0; i < group.size() - 1; i++) {
        group[i]->next = group[i+1];
    }
    group[group.size() - 1]->next = nullptr;
}

class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        if (head == nullptr) return head;
        
        auto nodess = split_list(head, k);
        for (auto &nodes : nodess) {
            reverse(nodes, k);
        }
        for (size_t i = 0; i < nodess.size() - 1; i++) {
            nodess[i][k-1]->next = nodess[i+1][0];
        }
        return nodess[0][0];
    }
};
