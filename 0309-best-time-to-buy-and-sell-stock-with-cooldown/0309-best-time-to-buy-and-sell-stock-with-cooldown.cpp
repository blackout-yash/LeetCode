class Solution {
public:
	int maxProfit(vector <int> &prices) {
		int n = prices.size();
		vector <int> dp(n);
		for (int i = 0; i < n; i++) {
			for (int j = i - 1; j >= 0; j--) {
				dp[i] = max(dp[i], dp[j]);
				if (j >= 2) dp[i] = max(dp[i], (prices[i] - prices[j]) + dp[j - 2]);
				else dp[i] = max(dp[i], prices[i] - prices[j]);
			}
		}
		return dp[n - 1];
	}
};