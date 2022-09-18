class Solution {
public:
	struct Trie {
		Trie *child[26];
		int cnt = 0;
	};

	Trie *getNode() {
		Trie *child = new Trie;
		for (int i = 0; i < 26; i++) child -> child[i] = NULL;

		return child;
	}

	void insert(Trie *root, string key) {
		Trie *pCrawl = root;

		for (int i = 0; i < key.length(); i++) {
			int index = key[i] - 'a';
			if (pCrawl -> child[index] == NULL)
				pCrawl -> child[index] = getNode();
			pCrawl = pCrawl -> child[index];
			pCrawl -> cnt++;
		}
	}

	vector <int> search(struct Trie *root, string key) {
		vector <int> ans;
		struct Trie *pCrawl = root;
		for (int i = 0; i < key.length(); i++) {
			int index = key[i] - 'a';
			if (!pCrawl -> child[index]) return ans;
			pCrawl = pCrawl -> child[index];
			ans.push_back(pCrawl -> cnt);
		}

		return ans;
	}
    
	vector<int> sumPrefixScores(vector<string> &words) {
        int n = words.size();
        
        Trie *root = getNode();
        for(int i = 0; i < n; i++) insert(root, words[i]);
        
        vector <int> ans;
        for(int i = 0; i < n; i++){
            int cnt = 0;
            vector <int> temp = search(root, words[i]);
            for(auto x: temp) cnt += x;    
            ans.push_back(cnt);
        }
        return ans;
	}
};