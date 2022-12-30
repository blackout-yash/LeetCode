//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
	string removeOuter(string &str) {
		string ans;
		stack <char> s;
		for (auto x : str) {
			if (s.empty()) s.push(x);
			else if (x == '(') {
				s.push(x);
				ans.push_back(x);
			} else {
				if (s.size() == 1) s.pop();
				else {
				    s.pop();
					ans.push_back(x);
				}
			}
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
        Solution obj;

        cout << obj.removeOuter(s) << "\n";
    }
}
// } Driver Code Ends