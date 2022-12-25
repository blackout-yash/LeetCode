class Node {
public:
	Node* links[26];
	bool flag = false;

	bool containKey(char ch) {
		return (links[ch - 'a'] != NULL);
	}

	void put(char ch, Node *node) {
		links[ch - 'a'] = node;
	}

	Node* get(char ch) {
		return links[ch - 'a'];
	}

	void setEnd() {
		flag = true;
	}

	bool isEnd() {
		return flag;
	}
};

class Trie {
public:
	Node* root;

	Trie() {
		root = new Node();
	}

	void insert(string word) {
		Node* node = root;
		for (auto x : word) {
			if (node -> containKey(x) == false) {
				node -> put(x, new Node());
			}
			node = node -> get(x);
		}
		node -> setEnd();
	}

	bool search(string word) {
		Node* node = root;
		for (auto x : word) {
			if (node -> containKey(x) == false) return false;
			node = node -> get(x);
		}
		return node -> isEnd();
	}

	bool startsWith(string prefix) {
		Node* node = root;
		for (auto x : prefix) {
			if (node -> containKey(x) == false) return false;
			node = node -> get(x);
		}
		return true;
	}
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */