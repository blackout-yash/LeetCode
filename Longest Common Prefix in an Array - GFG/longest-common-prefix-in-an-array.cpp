//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Node {
public:
	Node* links[26];
	int cntEndWith = 0;
	int cntPrefix = 0;

	bool containsKey(char ch) {
		return (links[ch - 'a'] != NULL);
	}

	Node* get(char ch) {
		return links[ch - 'a'];
	}

	void put(char ch, Node * node) {
		links[ch - 'a'] = node;
	}

	void increaseEnd() {
		cntEndWith++;
	}

	void increasePrefix() {
		cntPrefix++;
	}

	void deleteEnd() {
		cntEndWith--;
	}

	void reducePrefix() {
		cntPrefix--;
	}

	int getEnd() {
		return cntEndWith;
	}

	bool isEnd() {
		return cntEndWith;
	}

	int getPrefix() {
		return cntPrefix;
	}
};

class Trie {
public:
	Node* root;
	Trie() {
		root = new Node();
	}

	void insert(bool flag, string word) {
		Node* node = root;
		for (auto x : word) {
			if (node -> containsKey(x) == false) {
				if (flag) node -> put(x, new Node());
				else return;
			}
			node = node -> get(x);
			node -> increasePrefix();
		}
		node -> increaseEnd();
	}

	int maxLen(int n) {
		int cnt = 0;
		bool flag = true;
		Node* node = root;
		while (flag) {
			flag = false;
			for (int i = 0; i < 26; i++) {
				char ch = char('a' + i);
				if (node -> containsKey(ch)) {
					node = node -> get(ch);
					if (node -> cntPrefix == n) {
						cnt++; flag = true;
						break;
					}
				}
			}
		}
		return cnt;
	}

};

class Solution {
public:
	string longestCommonPrefix (string arr[], int n) {
		Trie T;
		T.insert(true, arr[0]);

		for (int i = 1; i < n; i++) {
			T.insert(false, arr[i]);
		}

		string ans;
		int cnt = T.maxLen(n);
		for (int i = 0; i < cnt; i++) ans.push_back(arr[0][i]);
		
		if(ans.empty()) return "-1";
		return ans;
	}
};

//{ Driver Code Starts.
int main()
{
    int t; cin >> t;
    while (t--)
    {
        int n; cin >> n;
        string arr[n];
        for (int i = 0; i < n; ++i)
            cin >> arr[i];
        
        Solution ob;
        cout << ob.longestCommonPrefix (arr, n) << endl;
    }
}

// Contributed By: Pranay Bansal

// } Driver Code Ends