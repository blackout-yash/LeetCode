class Solution {
public:
    vector <vector <int>> move = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
    
    bool isValid(int i, int j, int n) {
        return i >= 0 && i < n && j >= 0 && j < n;
    }
    
    bool isConn(int i, int j, vector<vector<int>> &grid) {
        if(i && grid[i - 1][j]) return 1;
        else if(j && grid[i][j - 1]) return 1;
        return 0;
    }
    
    void dfs(int i, int j, int n, queue <pair <int, int>> &q, vector<vector<int>> &vis, vector<vector<int>> &grid) {
        vis[i][j] = 1;
        q.push({i, j});
        
        for(auto it: move) {
            int x = it[0] + i,
                y = it[1] + j;
            if(!isValid(x, y, n) || vis[x][y] || !grid[x][y]) continue;
            dfs(x, y, n, q, vis, grid);
        }
    }
    
    int shortestBridge(vector<vector<int>> &grid) {
        int n = grid.size();
        
        queue <pair <int, int>> q;
        vector <vector <int>> vis(n, vector <int> (n));
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                if(grid[i][j]) {
                    dfs(i, j, n, q, vis, grid);
                    break;
                }
            }
            if(q.size()) break;
        }
        
        int ans = 1e9; 
        while(q.size()) {
            int x = q.front().first, 
                y = q.front().second;
            q.pop();
            
            for(auto it: move) {
                int currX = x + it[0],
                    currY = y + it[1];
                
                if(isValid(currX, currY, n) && !vis[currX][currY]) {
                    q.push({currX, currY});
                    vis[currX][currY] = 1 + vis[x][y];
                    if(grid[currX][currY]) ans = min(ans, vis[currX][currY]);
                }
            }
        }
        
        return ans - 2;
    }
};