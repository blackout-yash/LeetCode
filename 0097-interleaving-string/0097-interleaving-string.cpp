class Solution {
public:
    bool isInterleave(int i, int j, int k, int n, int m, string &s1, string &s2, string &s3, vector <vector <int>> &dp) {
        if(i == n && j == m) return true;
        else if(dp[i][j] != -1) return dp[i][j];
        
        bool ans1 = false;
        if(i != n && s1[i] == s3[k]) ans1 = isInterleave(i + 1, j, k + 1, n, m, s1, s2, s3, dp);
        
        bool ans2 = false;
        if(j != m && s2[j] == s3[k]) ans2 = isInterleave(i, j + 1, k + 1, n, m, s1, s2, s3, dp);
        
        return dp[i][j] = (ans1 | ans2);
    }
    
    bool isInterleave(string s1, string s2, string s3) {
        int n = s1.size(), m = s2.size();
        if(n + m != s3.size()) return false;
        vector <vector <int>> dp(n + 1, vector <int> (m + 1, -1));
        return isInterleave(0, 0, 0, n, m, s1, s2, s3, dp);
    }
};