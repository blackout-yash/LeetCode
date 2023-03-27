class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        vector <int> dp(m, 1e9);
        dp[0] = 0;
        for(int i = 0; i < n; i++) {
            vector <int> curr(m, 1e9);
            for(int j = 0; j < m; j++) {
                curr[j] = min({curr[j], dp[j] + grid[i][j], curr[max(0, j - 1)] + grid[i][j]});
            } dp = curr;
        }
        return dp[m - 1];
    }
};