class Solution {
public:
	int minCost(string colors, vector<int> &neededTime) {
		int n = colors.size();
		vector <vector<int>> dp(n + 1, vector<int> (26));
		for (int i = 1; i <= n; i++) {
			int ind = colors[i - 1] - 'a', _min = 1e9;
			for (int j = 0; j < 26; j++) {
				if (ind != j) _min = min(_min, dp[i - 1][j]);
				dp[i][j] = dp[i - 1][j] + neededTime[i - 1];
			}
			dp[i][ind] = min(_min, dp[i][ind]);
		}
		return *min_element(dp[n].begin(), dp[n].end());
	}
};