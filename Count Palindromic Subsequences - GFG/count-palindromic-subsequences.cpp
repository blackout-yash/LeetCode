//{ Driver Code Starts
// Counts Palindromic Subsequence in a given String
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
    public:
    int add(int a, int b, int m = 1e9 + 7) {a %= m; b %= m; return (((a + b) % m) + m) % m;}
    int sub(int a, int b, int m = 1e9 + 7) {a %= m; b %= m; return (((a - b) % m) + m) % m;}
    long long int  countPS(string s){
        int n = s.size();
        vector <vector <int>> dp(n + 2, vector <int> (n + 2));
        for(int i = n; i >= 1; i--) {
            for(int j = i; j <= n; j++) {
                int ans1 = dp[i + 1][j],
                    ans2 = dp[i][j - 1],
                    ans3 = dp[i + 1][j - 1],
                    ans4 = (s[i - 1] == s[j - 1]) * (1 + dp[i + 1][j - 1]);
                dp[i][j] = add(sub(add(ans1, ans2), ans3), ans4);
            }
        }
        return dp[1][n];
    }
     
};

//{ Driver Code Starts.
// Driver program
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        string str;
        cin>>str;
        Solution ob;
        long long int ans = ob.countPS(str);
        cout<<ans<<endl;
    } 
}
// } Driver Code Ends