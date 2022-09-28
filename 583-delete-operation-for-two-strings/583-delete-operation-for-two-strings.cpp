class Solution {
public:    
    int minDistance(string word1, string word2) {
        int n = word1.size(), m = word2.size();
        vector <vector <int>> dp(n, vector <int> (m));
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++){
                int ans1 = 2 * (word1[i] != word2[j]);
                if(i && j) ans1 += dp[i - 1][j - 1];
                else ans1 += (i + j);
                
                int ans2 = 1e9;
                if(i) ans2 = 1 + dp[i - 1][j];
                
                int ans3 = 1e9;
                if(j) ans3 = 1 + dp[i][j - 1];
                
                dp[i][j] = min({ans1, ans2, ans3}); 
            }
        }
                
        return dp[n - 1][m - 1];
    }
};