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
	ListNode* middle(ListNode* head) {
		ListNode* fast = head -> next;
		ListNode* slow = head;
		while (true) {
			if (fast == NULL || fast -> next == NULL) return slow;
			fast = fast -> next -> next;
			slow = slow -> next;
		}
		return NULL;
	}

	ListNode* merge(ListNode* left, ListNode* right) {
		ListNode* head = new ListNode(0);
		ListNode* temp = head;
		while (left && right) {
			if ((left -> val) > (right -> val)) {
				head -> next = right;
				right = right -> next;
			} else {
				head -> next = left;
				left = left -> next;
			}
			head = head -> next;
		}

		while (left) {
			head -> next = left;
			left = left -> next;
			head = head -> next;
		}

		while (right) {
			head -> next = right;
			right = right -> next;
			head = head -> next;
		}
		head -> next = NULL;

		return temp -> next;
	}
    
	ListNode* sortList(ListNode* head) {
		if (head == NULL || head -> next == NULL) return head;
        
		ListNode* mid = middle(head);
        
		ListNode* left = head;
		ListNode* right = mid -> next;
		mid -> next = NULL;

		left = sortList(left);
		right = sortList(right);

		return merge(left, right);
	}
};