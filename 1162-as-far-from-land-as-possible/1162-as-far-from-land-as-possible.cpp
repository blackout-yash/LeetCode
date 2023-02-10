class Solution {
public:
    bool isValid(int x, int y, int n) {
        return x >= 0 && x < n && y >= 0 && y < n;
    }

    vector <vector<int>> movement = {
	    { -1, 0}, {0, -1}, {0, 1}, {1, 0}
    };

    int maxDistance(vector<vector<int>> &grid) {
        int n = grid.size();
        queue <pair<int, int>> q;
        vector <vector<int>> vis(n, vector<int> (n));
        
        int ans = -1;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j]) {
                    vis[i][j] = 1;
                    q.push({i, j});
                }
            }
        }
        
        while (!q.empty()) {
            int x = q.front().first,
                y = q.front().second;
            q.pop();
            
            if (!grid[x][y]) ans = max(ans, vis[x][y] - 1);

            for (auto it : movement) {
                int currX = x + it[0],
                    currY = y + it[1];
                if (isValid(currX, currY, n) && !vis[currX][currY]) {
                    q.push({currX, currY});
                    vis[currX][currY] = 1 + vis[x][y];
                }
            }
        }
        return ans;
    }
};