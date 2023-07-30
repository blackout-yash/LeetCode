class Solution {
public:
    int strangePrinter(string s) {
        int n = s.size();
        vector <vector <int>> dp(n, vector <int> (n, 1e9));
        for(int i = n - 1; i >= 0; i--) {
            for(int j = i; j < n; j++) {
                if(i == j) dp[i][j] = 1;
                else {
                    for(int k = i; k < j; k++) {
                        int ans1 = dp[i][k],
                            ans2 = dp[k + 1][j];
                        if(s[i] == s[j]) dp[i][j] = min(dp[i][j], ans1 + ans2 - 1);
                        else dp[i][j] = min(dp[i][j], ans1 + ans2);
                    }
                }
            }
        }
        return dp[0][n - 1];
    }
};