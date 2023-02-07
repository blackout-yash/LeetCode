class Node {
public:
	int val;
	Node* next;
	Node* prev;
	Node(int value) {
		val = value;
		next = prev = NULL;
	}
};

class MyCircularDeque {
	Node* front;
    Node* rear;
	int maxSize, currSize;
public:
	void remove(Node* node) {
		Node* next = node -> next;
		Node* prev = node -> prev;
		prev -> next = next;
		next -> prev = prev;
	}

	void insert(Node* node, int value) {
		Node* dummy = new Node(value);
		Node* next = node -> next;
		node -> next = dummy;
		dummy -> prev = node;
		dummy -> next = next;
		next -> prev = dummy;
	}

	MyCircularDeque(int k) {
		maxSize = k;
		currSize = 0;
		front = new Node(-1);
		rear = new Node(-1);
		front -> next = rear;
		rear -> prev = front;
	}

	bool insertFront(int value) {
		if (isFull()) return 0;
		currSize++;
		insert(front, value);
		return 1;
	}

	bool insertLast(int value) {
		if (isFull()) return 0;
		currSize++;
		insert(rear -> prev, value);
		return 1;
	}

	bool deleteFront() {
		if (isEmpty()) return 0;
		currSize--;
		Node* dummy = front -> next;
		remove(dummy);
		delete(dummy);
		return 1;
	}

	bool deleteLast() {
		if (isEmpty()) return 0;
		currSize--;
		Node* dummy = rear -> prev;
		remove(dummy);
		delete(dummy);
		return 1;
	}

	int getFront() {
		if (isEmpty()) return -1;
		return front -> next -> val;
	}

	int getRear() {
		if (isEmpty()) return -1;
		return rear -> prev -> val;
	}

	bool isEmpty() {
		return (currSize == 0);
	}

	bool isFull() {
		return (currSize == maxSize);
	}
};