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
    ListNode *reverseLL(ListNode* head) {
        ListNode *newHead = NULL;
        while(head != NULL) {
            ListNode *next = head -> next;
            head -> next = newHead;
            newHead = head;
            head = next;
        }
        return newHead;
    }
    
    bool isPalindrome(ListNode* head) {
        ListNode *fast = head;
        ListNode *slow = head;
        while(true) {
            if(fast -> next == NULL || fast -> next -> next == NULL) break;
            fast = fast -> next -> next;
            slow = slow -> next;
        }
                
        ListNode *temp = slow -> next;
        ListNode *newHead = reverseLL(temp);
        
        ListNode *first = head;
        ListNode *second = newHead;
        while(true) {
            if(second == NULL) break;
            else if(first -> val != second -> val) return false;
            first = first -> next;
            second = second -> next;
        }
        
        ListNode *reverse = reverseLL(newHead);
        slow -> next = reverse;
        
        while(head) {
            cout << head -> val << " ";
            head = head -> next;
        }
        
        return true;
    }
};