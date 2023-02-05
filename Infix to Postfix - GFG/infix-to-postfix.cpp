//{ Driver Code Starts
// C++ implementation to convert infix expression to postfix
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
public:
	string infixToPostfix(string str) {
		map <char, int> m;
		m['+'] = m['-'] = 1;
		m['*'] = m['/'] = 2;
		m['^'] = 3;

		string ans;
		stack <char> s;
		for (auto x : str) {
			if ('A' <= x && x <= 'Z') ans.push_back(x);
			else if ('a' <= x && x <= 'z') ans.push_back(x);
			else if (x == '(') s.push(x);
			else if (x == ')') {
				while (true) {
					if (s.top() == '(') {
						s.pop();
						break;
					}
					ans.push_back(s.top());
					s.pop();
				}
			} else {
				while (s.size() && m[s.top()] >= m[x]) {
					ans.push_back(s.top());
					s.pop();
				}
				s.push(x);
			}
		}
		while(s.size()) {
		    ans.push_back(s.top());
		    s.pop();
		}
		return ans;
	}
};



//{ Driver Code Starts.
// Driver program to test above functions
int main() {
    int t;
    cin >> t;
    cin.ignore(INT_MAX, '\n');
    while (t--) {
        string exp;
        cin >> exp;
        Solution ob;
        cout << ob.infixToPostfix(exp) << endl;
    }
    return 0;
}

// } Driver Code Ends