class Solution {
public:
	vector <vector <int>> movement = {
		{ -1, 0}, {0, -1}, {0, 1}, {1, 0}
	};

	bool isValid(int i, int j, int n, int m) {
		return i >= 0 && i < n && j >= 0 && j < m;
	}

	int dfs(int x, int y, int cnt, int &n, int &m, int &req, vector<vector<int>> &vis, vector<vector<int>> &grid) {
		if (grid[x][y] == -1) return 0;
		else if (grid[x][y] == 2) {
			if (cnt + 1 == req) return 1;
			return 0;
		}
		vis[x][y] = 1; cnt++;

		int ans = 0;
		for (auto it : movement) {
			int currX = x + it[0],
			    currY = y + it[1];
			if (isValid(currX, currY, n, m)) {
				if (!vis[currX][currY]) ans += dfs(currX, currY, cnt, n, m, req, vis, grid);
			}
		}
		vis[x][y] = 0; cnt--;
		return ans;
	}

	int uniquePathsIII(vector<vector<int>> &grid) {
		int n = grid.size(), m = grid[0].size();
		vector<vector<int>> vis(n, vector <int> (m));

		int x, y, req = n * m;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (grid[i][j] == 1) x = i, y = j;
				else if (grid[i][j] == -1) req--;
			}
		}

		int ans = dfs(x, y, 0, n, m, req, vis, grid);

		return ans;
	}
};