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
    ListNode* mergeKLists(vector<ListNode*>& lists){
        auto listCompare = [](ListNode* a, ListNode* b) {return a->val > b->val;};
        
        priority_queue<ListNode*, vector<ListNode*>, decltype(listCompare)> pq(listCompare);
        for(auto i: lists){
            if(i != nullptr){
                pq.push(i);
            }
        }
        
        if(pq.empty()){
            return nullptr;
        }
        auto top = pq.top();
        ListNode* head = new ListNode(top->val);
        pq.pop();
        if(top->next != nullptr){
            pq.push(top->next);
        }
        auto ptr = head;
                
        while(!pq.empty()){
            auto top = pq.top();
            ListNode* new_node = new ListNode(top->val);
            pq.pop();
            if(top->next != nullptr){
                pq.push(top->next);
            }
            ptr->next = new_node;
            ptr = ptr->next;
        }
    
        return head;
    }
};
