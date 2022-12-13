class Solution {
public:
	vector <vector <int>> movement = {
		{ -1, -1}, { -1, 0}, { -1, 1}
	};

	bool isValid(int i, int j, int n) {
		return i >= 0 && i < n && j >= 0 && j < n;
	}

	int minFallingPathSum(vector<vector<int>> &matrix) {
		int n = matrix.size();
		vector <vector<int>> dp(n, vector<int> (n, 1e9));
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (i) {
					for (auto move : movement) {
						int x = i + move[0],
						    y = j + move[1];
						if (isValid(x, y, n)) dp[i][j] = min(dp[i][j], matrix[i][j] + dp[x][y]);
					}
				} else dp[i][j] = matrix[i][j];
			}
		}

		int ans = 1e9;
		for (auto x : dp[n - 1]) ans = min(x, ans);

		return ans;
	}
};