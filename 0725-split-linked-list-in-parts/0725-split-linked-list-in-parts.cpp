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
    vector <ListNode*> splitListToParts(ListNode* head, int k) {
        int n = 0;
        ListNode* temp = head;
        while(temp) {
            n++;
            temp = temp -> next;
        }
        
        vector <ListNode*> ans;
        int que = n / k, rem = n % k; 
        for(int i = 0; i < k; i++) {
            ans.push_back(head);
            if(head == NULL) continue;
            
            ListNode* curr = head;
            int range = que + (rem != 0) - 1;
            while(range-- && curr) curr = curr -> next;
            
            if(curr) head = curr -> next;
            else head = NULL;
            
            if(curr) curr -> next = NULL;
            
            if(rem) rem--;
        }
        return ans;
    }
};