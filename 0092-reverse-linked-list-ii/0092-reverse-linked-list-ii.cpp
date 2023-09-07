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
    ListNode* reverseBetween(ListNode* head, int left, int right) {    
        if(left == right) return head;

        ListNode* curr = head;
        ListNode* prev = NULL;
        while(left-- - 1) {
            right--;
            prev = curr;
            curr = curr -> next;
        }
        
        ListNode* par = NULL;
        ListNode* dummy = curr;
        while(right--) {
            ListNode* next = dummy -> next;
            dummy -> next = par;
            par = dummy;
            dummy = next;
        } 
        curr -> next = dummy;
        
        if(prev) {
            prev -> next = par;
            return head;
        }
        return par;
    }
};