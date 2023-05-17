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
    int pairSum(ListNode* head) {
        stack <ListNode*> s;
        queue <ListNode*> q;
        while(head) {
            q.push(head);
            if(q.size() > s.size()) {
                s.push(q.front());
                q.pop();
            }
            head = head -> next;
        }
        int ans = 0;
        while(s.size()) {
            ans = max(ans, s.top() -> val + q.front() -> val);
            s.pop();
            q.pop();
        }
        return ans;
    }
};