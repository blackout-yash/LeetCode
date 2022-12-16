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
    ListNode* oddEvenList(ListNode* head) {
        if(head == NULL || head -> next == NULL) return head;
        
        ListNode *even = head;
        ListNode *odd = head -> next;
        ListNode *evenStart = even;
        ListNode *oddStart = odd;
        while(true) {
            if(odd == NULL || odd -> next == NULL) break;
            even -> next = even -> next -> next;
            odd -> next = odd -> next -> next;
            even = even -> next;
            odd = odd -> next;
        }
        even -> next = oddStart;
        return evenStart;
    }
};