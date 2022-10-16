class Solution {
public:
	int minDifficulty(vector<int> &jobDifficulty, int d) {
		int n = jobDifficulty.size();
		vector <vector<int>> dp(n + 1, vector<int> (d + 1, 1e5));
		dp[0][0] = 0;
		for (int i = 1; i <= n; i++) {
			for (int k = 1; k <= d; k++) {
				int _min = 1e5, _max = 0;
				for (int j = i; j > 0; j--) {
					_max = max(_max, jobDifficulty[j - 1]);
					_min = min(_min, _max + dp[j - 1][k - 1]);
				} dp[i][k] = _min;
			}
		}

		if (dp[n][d] >= 1e5) dp[n][d] = -1;
		return dp[n][d];
	}
};