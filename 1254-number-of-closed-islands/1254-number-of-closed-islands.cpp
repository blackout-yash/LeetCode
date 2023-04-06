class Solution {
public:
    vector <vector <int>> move = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
    
    bool isValid(int x, int y, int n, int m) {
        return x >= 0 && x < n && y >= 0 && y < m;
    }
    
    bool dfs(int x, int y, int n, int m, vector<vector<int>> &vis, vector<vector<int>> &grid) {
        vis[x][y] = 1;
        bool flag = false;
        for(auto it: move) {
            int currX = x + it[0],
                currY = y + it[1];
            if(isValid(currX, currY, n, m)) {
                if(vis[currX][currY]) continue;
                if(!grid[currX][currY]) flag |= dfs(currX, currY, n, m, vis, grid);  
            } else flag = true;
        }
        return flag;
    }

    int closedIsland(vector<vector<int>> &grid) {
        int n = grid.size(), m = grid[0].size();
        vector <vector <int>> vis(n, vector <int> (m));
        
        int ans = 0;
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(!vis[i][j] && !grid[i][j]) {
                    ans += (1 - dfs(i, j, n, m, vis, grid));
                }
            }
        }
        return ans;
    }
};