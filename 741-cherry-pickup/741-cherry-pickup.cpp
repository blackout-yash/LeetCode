class Solution {
public:
	int dp[60][60][60][60];

	vector <vector<int>> movements = {{0, 1}, {1, 0}};
	bool isValid(int i, int j, int n) {
		return i >= 0 && i < n && j >= 0 && j < n;
	}

	int cherryPickup(int i1, int j1, int i2, int j2, int n, vector <vector <int>> &grid) {
		if (!isValid(i1, j1, n) || !isValid(i2, j2, n)) return -2;
		else if (grid[i1][j1] == -1 || grid[i2][j2] == -1) return -2;

		int cherry = grid[i1][j1] + grid[i2][j2];
		if (i1 == i2 && j1 == j2) cherry -= grid[i1][j1];

		if (i1 + 1 == n && j1 + 1 == n) return cherry;
		else if (dp[i1][j1][i2][j2] != -1) return dp[i1][j1][i2][j2];

		int ans = -2;
		for (auto x : movements) {
			int currI1 = i1 + x[0],
			    currJ1 = j1 + x[1];
			for (auto y : movements) {
				int currI2 = i2 + y[0],
				    currJ2 = j2 + y[1];
				int curr = cherryPickup(currI1, currJ1, currI2, currJ2, n, grid);
				if (curr != -2) ans = max(ans, curr);
			}
		}

		if (ans != -2) ans += cherry;

		return dp[i1][j1][i2][j2] = ans;
	}

	int cherryPickup(vector <vector <int>> &grid) {
		int n = grid.size();
		memset(dp, -1, sizeof(dp));
		int ans = cherryPickup(0, 0, 0, 0, n, grid);
		if (ans == -2) ans = 0;
		return ans;
	}
};