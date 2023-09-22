class Solution {
public:
    int solve(string &A, string &B, int n, int m, vector <vector <int>> &dp) {
        if (n == 0 || m == 0) return 0;
        else if (dp[n][m] != -1) return dp[n][m];

        int ans;
        if (A[n - 1] == B[m - 1]) ans = 1 + solve(A, B, n - 1, m - 1, dp);
        else ans = max(solve(A, B, n - 1, m, dp), solve(A, B, n, m - 1, dp));

        return dp[n][m] = ans;
    }
    
    bool isSubsequence(string A, string B) {
        int n = A.size(), m = B.size();
        vector <vector <int>> dp(n + 1, vector <int>(m + 1, -1));

        if (n == solve(A, B, n, m, dp)) return true;
	return false;
    }
};