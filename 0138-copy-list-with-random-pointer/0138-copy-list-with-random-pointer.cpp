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
		map <Node*, Node*> m;
		Node* temp = head;
		while (temp) {
			m[temp] = new Node(temp -> val);
			temp = temp -> next;
		}

		temp = head;
		while (temp) {
			Node* dummy = m[temp];
			dummy -> next = m[temp -> next];
			dummy -> random = m[temp -> random];
			temp = temp -> next;
		}

		return m[head];
	}
};