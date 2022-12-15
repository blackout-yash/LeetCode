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
    bool hasCycle(ListNode *head) {
        if(head == NULL || head -> next == NULL) return false;
        
        ListNode* fast = head;
        ListNode* slow = head;
        
        while(true) {
            if(fast -> next == NULL || fast -> next -> next == NULL) break;
            fast = fast -> next -> next;
            slow = slow -> next;
            if(fast == slow) return true;
        }
        
        return false;
    }
};