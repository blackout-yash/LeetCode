class Solution {
public:
	int longestCommonSubsequence(string text1, string text2) {
		int n = text1.size(), m = text2.size();
		vector <vector<int>> dp(n, vector<int> (m));
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				int ans1 = 0;
				if (text1[i] == text2[j]) {
					if (i && j) ans1 = 1 + dp[i - 1][j - 1];
					else ans1 = 1;
				}

				int ans2 = 0;
				if (i) ans2 = dp[i - 1][j];

				int ans3 = 0;
				if (j) ans3 = dp[i][j - 1];

				dp[i][j] = max({ans1, ans2, ans3});
			}
		}
		return dp[n - 1][m - 1];
	}
};