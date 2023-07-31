class Solution {
public:
    int minimumDeleteSum(string s1, string s2) {
        int n = s1.size(), m = s2.size();
        vector <int> dp(m + 1);
        for(int i = 0; i <= n; i++) {
            vector <int> curr(m + 1);
            for(int j = 0; j <= m; j++) {
                if(i && j) {
                    int ans1 = dp[j - 1];
                    if(s1[i - 1] != s2[j - 1]) ans1 += (s1[i - 1] + s2[j - 1]); 
                
                    int ans2 = s1[i - 1] + dp[j];
                    int ans3 = s2[j - 1] + curr[j - 1];
                
                    curr[j] = min({ans1, ans2, ans3});
                } else if(i) curr[j] = s1[i - 1] + dp[j];
                else if(j) curr[j] = s2[j - 1] + curr[j - 1];
            }
            dp = curr;
        }
        
        return dp[m];
    }
};