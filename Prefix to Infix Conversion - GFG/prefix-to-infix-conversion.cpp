//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++
class Solution {
public:
	string preToInfix(string str) {
		stack <string> s;
		for (int i = str.size() - 1; i >= 0; i--) {
			if ('a' <= str[i] && str[i] <= 'z') s.push(string(1, str[i]));
			else if ('A' <= str[i] && str[i] <= 'Z') s.push(string(1, str[i]));
			else {
				string left = s.top();
				s.pop();
				string right = s.top();
				s.pop();
				string curr = "(" + left + str[i] + right + ")";
				s.push(curr);
			}
		}
		return s.top();
	}
};

//{ Driver Code Starts.
int main() {
    int t = 1;
    cin >> t;

    // freopen ("output_gfg.txt", "w", stdout);

    while (t--) {
        // Input
        string prefix;
        cin >> prefix;

        Solution obj;
        cout << obj.preToInfix(prefix) << endl;

        // cout << "~\n";
    }
    // fclose(stdout);

    return 0;
}

// } Driver Code Ends