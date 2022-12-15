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
    ListNode* reverse(ListNode* head, ListNode* newHead) {
        if(head == NULL) return newHead;
        
        ListNode* next = head -> next;
        head -> next = newHead;
        newHead = head;
        head = next;
        
        newHead = reverse(head, newHead);
        
        return newHead;
    }
    
    ListNode* reverseList(ListNode* head) {
        ListNode *newHead = NULL;
        
        return reverse(head, newHead);
    }
};