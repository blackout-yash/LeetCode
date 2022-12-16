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
        ListNode *fast = head;
        ListNode *slow = head;
        
        while(n--) fast = fast -> next;
        
        if(fast == NULL) return slow -> next;
        
        while(true) {
            if(fast -> next == NULL) {
                slow -> next = slow -> next -> next;
                break;
            }
            fast = fast -> next;
            slow = slow -> next;
        }
        return head;
    }
};