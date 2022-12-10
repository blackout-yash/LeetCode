class Solution {
public:
	int longestArithSeqLength(vector <int> &nums) {
		int n = nums.size(), ans = 0;
		for (int i = 0; i <= 500; i++) {
			vector <vector<int>> dp(2, vector<int> (501));
			for (int j = 0; j < n; j++) {
				int ind = nums[j];
				if (i + ind > 500) dp[0][ind] = 1;
				else dp[0][ind] = 1 + dp[0][ind + i];

				if (i > ind) dp[1][ind] = 1;
				else dp[1][ind] = 1 + dp[1][ind - i];

				ans = max({ans, dp[0][ind], dp[1][ind]});
			}
		}
		return ans;
	}
};