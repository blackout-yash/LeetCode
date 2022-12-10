class Solution {
public:
	int longestArithSeqLength(vector <int> &nums) {
		int n = nums.size(), ans = 0;

		// here, i denotes the common difference
		// since, 0 <= nums[i] <= 500, so maximum value of common differnce may be 500 or -500
		for (int i = 0; i <= 500; i++) {

			// 2d vector
			// 1st row for -ve common differnce
			// 2nd row for +ve common differnce
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