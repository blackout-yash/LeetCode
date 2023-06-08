class Solution {
public:
    int countNegatives(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size(), i = n - 1, j = 0, ans = 0;
        while(i >= 0) {
            while(j < m) {
                if(grid[i][j] < 0) break;
                else j++;
            } i--;
            ans += (m - j);
        }
        return ans;
    }
};