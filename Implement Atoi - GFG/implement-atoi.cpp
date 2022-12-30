//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution{
  public:
    int atoi(string s) {
        int n = s.size(), ans = 0, fact = 1;
        for(int i = n - 1; i >= 0; i--) {
            int digit = s[i] - '0';
            if(0 <= digit && digit <= 9) {
                ans += (fact * digit);
                fact *= 10;
            } else if(i == 0 && s[i] == '-') ans *= -1;
            else return -1;
        }
        return ans;
    }
};

//{ Driver Code Starts.
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		string s;
		cin>>s;
		Solution ob;
		cout<<ob.atoi(s)<<endl;
	}
}
// } Driver Code Ends