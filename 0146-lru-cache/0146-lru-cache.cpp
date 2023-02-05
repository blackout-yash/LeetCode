class LRUCache {
public:
	class Node {
	public:
		Node* next;
		Node* prev;
		int key, val;

		Node(int x, int y) {
			key = x;
			val = y;
			next = prev = NULL;
		}
	};

	void add(Node* dummy) {
		Node* next = head -> next;
		head -> next = dummy;
		dummy -> prev = head;
		dummy -> next = next;
		next -> prev = dummy;
	}

	void remove(Node* dummy) {
		Node* prev = dummy -> prev;
		Node* next = dummy -> next;
		prev -> next = next;
		next -> prev = prev;
	}

	int cap;
	Node* head;
	Node* tail;
	unordered_map <int, Node*> m;

	LRUCache(int capacity) {
		cap = capacity;
		head = new Node(-1, -1);
		tail = new Node(-2, -2);
		head -> next = tail;
		tail -> prev = head;
	}

	int get(int key) {
		if (m.count(key)) {
			Node* dummy = m[key];
			remove(dummy);
			add(dummy);
			return dummy -> val;
		}
		return -1;
	}

	void put(int key, int value) {
		if (m.count(key)) {
			Node* dummy = m[key];
			dummy -> val = value;
			remove(dummy);
			add(dummy);
			return;
		}

		if (cap == m.size()) {
			Node* dummy = tail -> prev;
			m.erase(dummy -> key);
			remove(dummy);
		}

		Node* dummy = new Node(key, value);
		m[key] = dummy;
		add(dummy);
	}
};