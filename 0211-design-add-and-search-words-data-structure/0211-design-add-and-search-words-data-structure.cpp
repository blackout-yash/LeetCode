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

	bool searchWord(int i, Node* node, string &word) {
        if(i == word.size()) return node -> isEnd();
        
        bool flag = 0;
        char ch = word[i];
        if(ch == '.') {
            for(int j = 0; j < 26; j++) {
                ch = char('a' + j);
                if(node -> containKey(ch)) flag = searchWord(i + 1, node -> get(ch), word);
                if(flag) break;
            }
        } else {
            if (node -> containKey(ch)) flag = searchWord(i + 1, node -> get(ch), word);
        }
        
        return flag;
	}
};

class WordDictionary {
public:
    Trie T;
    WordDictionary() {}
    
    void addWord(string word) {
        T.insert(word);
    }
    
    bool search(string word) {
        return T.searchWord(0, T.root, word);
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */