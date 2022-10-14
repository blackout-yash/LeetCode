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
    ListNode* deleteMiddle(ListNode* head) {
        ListNode* fast = head;
        ListNode* slow = head;
        
        while(true) {
            if(fast -> next == NULL || fast -> next -> next == NULL) {
                if(fast -> next == NULL) {}
                else slow = slow -> next;
                
                if(slow -> next != NULL) {
                    auto next = slow -> next;
                    *slow = *next;
                    delete next;
                    return head;
                } else {
                    if(fast -> next == NULL) return NULL;
                    ListNode *par = new ListNode(head -> val);
                    return par;            
                }
            } 
            fast = fast -> next -> next;
            slow = slow -> next;
        }
        return head;
    }
};