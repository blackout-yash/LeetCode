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
        
        ListNode* temp = head;
        vector <int> ans;
        while(temp) {
            ans.push_back(temp -> val);
            temp = temp -> next;
        }
        
        temp = head;
        for(int i = 0; i < ans.size(); i += 2) {
            head -> val = ans[i];
            head = head -> next;
        }
        
        for(int i = 1; i < ans.size(); i += 2) {
            head -> val = ans[i];
            head = head -> next;
        }
        
        return temp;
    }
};