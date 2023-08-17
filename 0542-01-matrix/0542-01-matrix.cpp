class Solution {
public:
    vector <vector <int>> move = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
    
    bool isValid(int i, int j, int n, int m) {
        return i >= 0 && i < n && j >= 0 && j < m;
    }
    
    vector <vector <int>> updateMatrix(vector<vector<int>> &mat) {
        queue <pair <int, int>> q;
        int n = mat.size(), m = mat[0].size();
        vector <vector <int>> vis(n, vector <int> (m, 1e9));
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(!mat[i][j]) {
                    q.push({i, j});
                    vis[i][j] = 0;
                }
            }
        }
        
        while(!q.empty()) {
            int x = q.front().first,
                y = q.front().second;
            q.pop();
            for(auto it: move) {
                int currX = it[0] + x,
                    currY = it[1] + y;
                if(isValid(currX, currY, n, m) && vis[currX][currY] > 1 + vis[x][y]) {
                    vis[currX][currY] = 1 + vis[x][y];
                    q.push({currX, currY});
                } 
            }
        }
        
        return vis;
    }
};