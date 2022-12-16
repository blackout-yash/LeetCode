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
    ListNode *detectCycle(ListNode *head) {
        if(head == NULL || head -> next == NULL) return NULL;
        
        ListNode *fast = head;
        ListNode *slow = head;
        while(true) {
            if(fast == NULL || fast -> next == NULL) return NULL;
            fast = fast -> next -> next;
            slow = slow -> next;
            if(fast == slow) break;
        } 
        
        ListNode *entry = head;
        while(true) {
            if(entry == slow) break;
            slow = slow -> next;
            entry = entry -> next;
        } 
        return entry;
    }
};