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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int firstDigit = l1->val + l2->val;
        l1 = l1->next;
        l2 = l2->next;
        
        ListNode *ret = new ListNode(firstDigit);
        ListNode *current = ret;
        
        while(true){
            bool quit_flag = true;
            
            int val = current->val;
            current->val = val % 10;
            int carry = val / 10;
            
            
            if(l1 != NULL){
                carry += l1->val;
                l1 = l1->next;
                quit_flag = false;
            }
            
            if(l2 != NULL){
                carry += l2->val;
                l2 = l2->next;
                quit_flag = false;
            }
            
            if(carry > 10){
                quit_flag = false;
            }
            
            if (carry != 0 || !quit_flag){
                current->next = new ListNode(carry);
                current = current->next;   
            }
            
            if (quit_flag){
                break;
            }
        }
        
        return ret;
    }
};

