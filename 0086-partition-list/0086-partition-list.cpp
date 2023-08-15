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
    ListNode* partition(ListNode* head, int x) {
        ListNode* curr = head;
        ListNode* prev = new ListNode(-1e9);
        prev -> next = head;
        
        bool flag = true;
        while(curr) {
            if(flag && curr -> val < x) prev = curr;
            if(curr -> val >= x && curr -> next && curr -> next -> val < x) {
                ListNode* next = curr -> next;
                ListNode* prevNext = prev -> next;
                if(prev -> val == -1e9) head = next;
                curr -> next = next -> next;
                prev -> next = next;
                next -> next = prevNext;
                prev = prev -> next;
                flag = false;           
            } else curr = curr -> next;
        }
        return head;
    }
};