#define pp pair<int, ListNode*>
class Solution {
public:
	ListNode* mergeKLists(vector<ListNode*> &lists) {
        if(lists.empty()) return NULL;
        
		ListNode* temp = new ListNode();
		ListNode* head = temp;
		priority_queue <pp, vector <pp>, greater <pp>> pq;
		for (auto x : lists) {
            if(x) pq.push({x -> val, x});
        }
		while (!pq.empty()) {
			ListNode* dummy = pq.top().second;
			pq.pop();

			temp -> next = dummy;
			temp = temp -> next;
			if (dummy -> next) {
				dummy = dummy -> next;
				pq.push({dummy -> val, dummy});
			}
		}
		return head -> next;
	}
};