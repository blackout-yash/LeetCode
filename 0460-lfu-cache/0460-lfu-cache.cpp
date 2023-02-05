class Node {
public:
	Node* next;
	Node* prev;
	int key, val, cnt;

	Node(int x, int y) {
		cnt = 1;
		key = x;
		val = y;
		next = prev = NULL;
	}
};

class List {
public:
	int size;
	Node* head;
	Node* tail;

	List() {
		size = 0;
		head = new Node(-1, -1);
		tail = new Node(-2, -2);
		head -> next = tail;
		tail -> prev = head;
	}

	void add(Node* dummy) {
		size++;
		Node* next = head -> next;
		head -> next = dummy;
		dummy -> prev = head;
		dummy -> next = next;
		next -> prev = dummy;
	}

	void remove(Node* dummy) {
		size--;
		Node* prev = dummy -> prev;
		Node* next = dummy -> next;
		prev -> next = next;
		next -> prev = prev;
	}
};

class LFUCache {
public:
	int cap, minFreq;
	unordered_map <int, List*> freqNode;
	unordered_map <int, Node*> keyNode;

	void addNextFreq(int freq) {
		if (!freqNode.count(freq)) {
			List* nextFreqList = new List();
			freqNode[freq] = nextFreqList;
		}
	}

	void UpdateMinFreq() {
		if (keyNode.empty()) {
            minFreq = 0;
            return;
        }
		while (true) {
			if (freqNode[minFreq] -> size) break;
			else minFreq++;
		}
	}

	void updateNode(Node* dummy) {
		int currFreq = dummy -> cnt;
		freqNode[currFreq] -> remove(dummy);

		int nextFreq = currFreq + 1;
		addNextFreq(nextFreq);

		dummy -> cnt = nextFreq;
		freqNode[nextFreq] -> add(dummy);
        UpdateMinFreq();
	}

	LFUCache(int capacity) {
		minFreq = 0;
		cap = capacity;
	}

	int get(int key) {
        if(!cap) return -1;
		if (keyNode.count(key)) {
			Node* dummy = keyNode[key];
			updateNode(dummy);
			return (dummy -> val);
		} return -1;
	}

	void put(int key, int value) {
        if(!cap) return;
		if (keyNode.count(key)) {
			Node* dummy = keyNode[key];
			updateNode(dummy);
			dummy -> val = value;
			return;
		}

		if (keyNode.size() == cap) {
			List* dummy = freqNode[minFreq];
            keyNode.erase(dummy -> tail -> prev -> key);
			dummy -> remove(dummy -> tail -> prev);
			UpdateMinFreq();
		}

		minFreq = 1;
		addNextFreq(minFreq);
		Node* dummy = new Node(key, value);
		keyNode[key] = dummy;
		freqNode[minFreq] -> add(dummy);
	}
};