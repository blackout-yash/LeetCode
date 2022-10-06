class Solution {
public:
    bool checkPartitioning(string s) {
        int n = s.size();
        vector <vector <int>> dp(n, vector <int> (n));
        for(int i = n - 1; i >= 0; i--){
            for(int j = 0; j < n; j++){
                if(i > j) continue;
                else if(i == j) dp[i][j] = 1;
                else if(j - i <= 2) dp[i][j] = (s[i] == s[j]);
                else {
                    if(s[i] == s[j]) dp[i][j] = dp[i + 1][j - 1];
                    else dp[i][j] = 0;
                }
            }
        }
        
        for(int i = 0; i < n - 2; i++){
            for(int j = i + 1; j < n - 1; j++) {
                if(dp[0][i] && dp[i + 1][j] && dp[j + 1][n - 1]) return true;
            }
        }
        
        return false;
    }
};