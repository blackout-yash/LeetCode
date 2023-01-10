//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution {
public:
	int longestKSubstr(string s, int k) {
		map <char, int> m;
		int ans = -1, size = 0, n = s.size(), left = 0;
		for (int i = 0; i < n; i++) {
			m[s[i]]++;
			while (m.size() > k) {
				m[s[left]]--;
				if (m[s[left]] == 0) m.erase(s[left]);
				left++;
			}
			if (m.size() == k) ans = max(ans, i - left + 1);
		}
		return ans;
	}
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        int k;
        cin >> k;
        Solution ob;
        cout << ob.longestKSubstr(s, k) << endl;
    }
}

// } Driver Code Ends