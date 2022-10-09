class Solution {
public:
	int add(int a, int b, int m = 1e9 + 7) {a %= m; b %= m; return (((a + b) % m) + m) % m;}

	int numberOfPaths(vector<vector<int>> &grid, int k) {
		int n = grid.size(), m = grid[0].size();
		vector <vector<vector <int>>> dp(n, vector<vector <int>> (m, vector <int> (k)));
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				int rem = grid[i][j] % k;
				for (int ind = 0; ind < k; ind++) {
					int req = ((ind - rem) + k) % k;

					if (!i && !j) {
						if (rem == ind) dp[i][j][ind] = 1;
						continue;
					}

					int ans1 = 0;
					if (i) ans1 = dp[i - 1][j][req];

					int ans2 = 0;
					if (j) ans2 = dp[i][j - 1][req];

					dp[i][j][ind] = add(ans1, ans2);
				}
			}
		}        

		return dp[n - 1][m - 1][0];
	}
};