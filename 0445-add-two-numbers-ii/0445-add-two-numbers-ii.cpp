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
    ListNode* reverse(ListNode* l) {
        ListNode* curr = l;
        ListNode* prev = NULL;
        while(curr) {
            ListNode* next = curr -> next;
            curr -> next = prev;
            prev = curr;
            curr = next;
        }
        return prev;
    }
    
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* revL1 = reverse(l1);
        ListNode* revL2 = reverse(l2);
        
        int carry = 0;
        ListNode* dummy = new ListNode(-1);
        ListNode* ans = dummy;
        
        while(revL1 && revL2) {
            int num1 = revL1 -> val,
                num2 = revL2 -> val,
                sum = num1 + num2 + carry;
            
            ListNode* temp = new ListNode(sum % 10);
            carry = sum / 10;

            dummy -> next = temp;
            dummy = dummy -> next;
            
            revL1 = revL1 -> next;
            revL2 = revL2 -> next;
        }
        
        while(revL1) {
            int num = revL1 -> val,
                sum = num + carry;
            
            ListNode* temp = new ListNode(sum % 10);
            carry = sum / 10;

            dummy -> next = temp;
            dummy = dummy -> next;
            
            revL1 = revL1 -> next;
        }
        
        while(revL2) {
            int num = revL2 -> val,
                sum = num + carry;
            
            ListNode* temp = new ListNode(sum % 10);
            carry = sum / 10;

            dummy -> next = temp;
            dummy = dummy -> next;
            
            revL2 = revL2 -> next;
        }
        
        if(carry) dummy -> next = new ListNode(carry);

        return reverse(ans -> next);
    }
};