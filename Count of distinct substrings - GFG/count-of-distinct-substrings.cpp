//{ Driver Code Starts
#include<bits/stdc++.h>

using namespace std;

int countDistinctSubstring(string s);

int main()
{
 int t,l,i,j;
 int temp;
    cin>>t;
 while(t--){
 string s;
  cin>>s;
  cout<<countDistinctSubstring(s)<<endl;

 }
}


// } Driver Code Ends


/*You are required to complete this method */
class Node {
public:
	Node* links[26];
	bool flag = false;

	bool containsKey(char ch) {
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

	int insert(string word) {
		int cnt = 1, n = word.size();
		for (int i = 0; i < n; i++) {
			string str;
			Node* node = root;
			for (int j = i; j < n; j++) str.push_back(word[j]);
			for (auto x : str) {
				if (!node -> containsKey(x)) {
					cnt++;
					node -> put(x, new Node());
				} 
				node = node -> get(x);
			}
		}
		return cnt;
	}
};


int countDistinctSubstring(string s) {
	Trie T;

	int ans = T.insert(s);

	return ans;
}