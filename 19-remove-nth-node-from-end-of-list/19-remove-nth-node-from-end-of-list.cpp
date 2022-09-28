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
        int size = 0;
        ListNode* temp = head;
        while(temp){
            size++;
            temp = temp -> next;
        } n = size - n;
        
        ListNode* prev = NULL;
        if(!n) return head -> next;
        
        temp = head;
        while(true){
            if(n) prev = temp;
            else {
                prev -> next = temp -> next;
                break;
            } n--;
            temp = temp -> next;
        }
        
        return head;
    }
};