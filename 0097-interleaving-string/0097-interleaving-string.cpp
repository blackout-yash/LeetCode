class Solution {
public:
    bool isInterleave(int n, int m, int k, string &s1, string &s2, string &s3, vector <vector <int>> &dp) {
        if(n == -1 && m == -1) return true;
        else if(dp[n + 1][m + 1] != -1) return dp[n + 1][m + 1];
        
        bool ans1 = false;
        if(n != -1 && s1[n] == s3[k]) ans1 = isInterleave(n - 1, m, k - 1, s1, s2, s3, dp);
        
        bool ans2 = false;
        if(m != -1 && s2[m] == s3[k]) ans2 = isInterleave(n, m - 1, k - 1, s1, s2, s3, dp);
        
        return dp[n + 1][m + 1] = (ans1 | ans2);
    }
    
    bool isInterleave(string s1, string s2, string s3) {
        int n = s1.size(), m = s2.size(), k = s3.size();
        if(n + m != k) return false;
        vector <vector <int>> dp(n + 1, vector <int> (m + 1, -1));
        return isInterleave(n - 1, m - 1, k - 1, s1, s2, s3, dp);
    }
};