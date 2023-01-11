//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution {
public:
	string reverseWords(string s) {
		string ans;
		int n = s.size(), j = n - 1;
		for (int i = n - 1; i >= 0; i--) {
			if (i == 0 || s[i] == '.') {
				if(j != n - 1) ans.push_back('.');
				for (int k = i; k <= j; k++) {
				    if(s[k] != '.') ans.push_back(s[k]);
				}
				j = i - 1;
			}
		}
		return ans;
	}
};

//{ Driver Code Starts.
int main() 
{
    int t;
    cin >> t;
    while (t--) 
    {
        string s;
        cin >> s;
        Solution obj;
        cout<<obj.reverseWords(s)<<endl;
    }
}
// } Driver Code Ends