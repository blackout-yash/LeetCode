class Solution {
public:
	int minCost(int i, char prev, string &colors, vector <int> &neededTime, vector <vector<int>> &dp) {
		if (i == -1) return 0;
		else if (dp[i][prev - 'a'] != -1) return dp[i][prev - 'a'];

		int ans1 = 1e9;
		if (prev != colors[i]) ans1 = minCost(i - 1, colors[i], colors, neededTime, dp);
		int ans2 = neededTime[i] + minCost(i - 1, prev, colors, neededTime, dp);

		return dp[i][prev - 'a'] = min(ans1, ans2);
	}

	int minCost(string colors, vector<int> &neededTime) {
		int n = colors.size();
		vector <vector<int>> dp(n, vector<int> (30, -1));

		int ans = minCost(n - 1, '{', colors, neededTime, dp);

		return ans;
	}
};