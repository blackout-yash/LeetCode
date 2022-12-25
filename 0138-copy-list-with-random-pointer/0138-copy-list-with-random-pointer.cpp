/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;

    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
	Node* copyRandomList(Node* head) {
        if(head == NULL) return head;
        
		Node* temp = head;
		while (temp) {
			Node* dummy = new Node(temp -> val);
			dummy -> next = temp -> next;
			temp -> next = dummy;
			temp = temp -> next -> next;
		}

		temp = head;
		Node* newHead = head -> next;
		while (temp) {
			Node* next = temp -> next;
			Node* random = temp -> random;
            if(random) {
                Node* randomNext = random -> next;
			    next -> random = randomNext;
            }
			temp = temp -> next -> next;
		}
        
        temp = head;
        Node* alpha = newHead;
        while(temp) {
            temp -> next = temp -> next -> next;
            if(alpha -> next) alpha -> next = alpha -> next -> next;
            temp = temp -> next;
            alpha = alpha -> next;
        } 

		return newHead;
	}
};