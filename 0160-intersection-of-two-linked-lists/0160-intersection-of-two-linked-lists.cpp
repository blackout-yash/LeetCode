/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
	ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
		ListNode *tempA = headA;
		ListNode *tempB = headB;

		int lenA = 0, lenB = 0;
		while (true) {
			if (tempA != NULL) {
				lenA++;
				tempA = tempA -> next;
			}
			if (tempB != NULL) {
				lenB++;
				tempB = tempB -> next;
			}
			if (tempA == NULL && tempB == NULL) break;
		}

		tempA = headA;
		tempB = headB;
		if (lenA > lenB) {
			while (lenA != lenB) {
				if (tempA == tempB) return tempA;
				lenA--;
				tempA = tempA -> next;
			}
		} else {
			while (lenA != lenB) {
				if (tempA == tempB) return tempA;
				lenB--;
				tempB = tempB -> next;
			}
		}

		while (true) {
			if (tempA == NULL || tempB == NULL) break;
			else if (tempA == tempB) return tempA;
			tempA = tempA -> next;
			tempB = tempB -> next;
		}

		return NULL;
	}
};