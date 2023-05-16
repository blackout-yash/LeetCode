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
        if(head == NULL || head -> next == NULL) return head;
        
        ListNode* prev = NULL;
        ListNode* curr = head;
        ListNode* start = head -> next;
        while(true) {
            if(curr == NULL || curr -> next == NULL) break;
            ListNode* next = curr -> next;
            if(prev) prev -> next = next;
            curr -> next = next -> next;
            next -> next = curr;
            prev = curr;
            curr = curr -> next;
        }
        return start;
    } 
};