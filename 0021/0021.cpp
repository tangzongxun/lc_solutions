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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode *ptr1 = l1, *ptr2 = l2;
        ListNode *dummy = new ListNode(0);
        ListNode *curr = dummy;
        
        while(ptr1 != nullptr && ptr2 != nullptr){
            if(ptr1->val < ptr2->val){
                curr->next = new ListNode(ptr1->val);
                curr = curr->next;
                ptr1 = ptr1->next;
            } else {
                curr->next = new ListNode(ptr2->val);
                curr = curr->next;
                ptr2 = ptr2->next;
            }
        }
        
        if(ptr1 == nullptr){
            curr->next = ptr2;
        } else{
            curr->next = ptr1;
        }
        
        return dummy->next;
              
    }
};
