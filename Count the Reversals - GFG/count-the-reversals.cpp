//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

int countRev (string s);
int main()
{
    int t; cin >> t;
    while (t--)
    {
        string s; cin >> s;
        cout << countRev (s) << '\n';
    }
}

// Contributed By: Pranay Bansal
// } Driver Code Ends


int countRev (string str) {
	int ans = 0;
	stack <char> s;
	for (auto x : str) {
		if (x == '}') {
			if (s.empty()) {
				ans++;
				s.push('{');
			} else s.pop();
		} else s.push(x);
	}
	if (s.size() & 1) return -1;
	ans += s.size() / 2;
	return ans;
}