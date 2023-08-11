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
    ListNode* removeZeroSumSublists(ListNode* head) {
        ListNode* curr = head;
        map <int, ListNode*> m;
        
        int sum = 0;
        while(curr) {
            sum += curr -> val;
            
            if(sum == 0) {
                curr = curr -> next;
                head = curr, m.clear();
                continue;
            }
            
            if(m.count(sum)) {
                ListNode* dummy = m[sum];
                int alpha = sum;
                while(true) {
                    ListNode *next = dummy -> next;
                    alpha += next -> val;
                    dummy -> next = next -> next;
                    if(next == curr) break;
                    else m.erase(alpha);
                }
            } else m[sum] = curr;
            curr = curr -> next;
        }
        return head;
    }
};