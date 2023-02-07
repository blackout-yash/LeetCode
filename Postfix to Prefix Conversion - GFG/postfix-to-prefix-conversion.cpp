//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    string postToPre(string post_exp) {
		stack <string> s;
		for (auto x : post_exp) {
		    if ('a' <= x && x <= 'z') s.push(string(1, x));
			else if ('A' <= x && x <= 'Z') s.push(string(1, x));
			else {
				string right = s.top();
				s.pop();
				string left = s.top();
				s.pop();
				
				string curr = x + left + right;
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
        string postfix;
        cin >> postfix;

        // char marker; cin >> marker;

        Solution obj;
        cout << obj.postToPre(postfix) << endl;

        // cout << "~\n";
    }
    // fclose(stdout);

    return 0;
}

// } Driver Code Ends