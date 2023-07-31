class Solution {
public:
    int minimumDeleteSum(string s1, string s2) {
        int n = s1.size(), m = s2.size();
        vector <vector <int>> dp(n + 1, vector <int> (m + 1));
        for(int i = 0; i <= n; i++) {
            for(int j = 0; j <= m; j++) {
                if(i && j) {
                    int ans1 = dp[i - 1][j - 1];
                    if(s1[i - 1] != s2[j - 1]) ans1 += (s1[i - 1] + s2[j - 1]); 
                
                    int ans2 = s1[i - 1] + dp[i - 1][j];
                    int ans3 = s2[j - 1] + dp[i][j - 1];
                
                    dp[i][j] = min({ans1, ans2, ans3});
                } else if(i) dp[i][j] = s1[i - 1] + dp[i - 1][j];
                else if(j) dp[i][j] = s2[j - 1] + dp[i][j - 1];
            }
        }
        
        return dp[n][m];
    }
};