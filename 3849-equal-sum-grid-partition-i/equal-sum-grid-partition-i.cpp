class Solution {
public:
    bool canPartitionGrid(vector<vector<int>>& grid) {
        long sum = 0;
        for(auto x: grid) 
            for(auto y: x) sum += y;
        if(sum & 1) return false;

        long n = grid.size(), m = grid[0].size(), curr = 0;
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) curr += grid[i][j];
            if(2 * curr == sum) return true;
        }

        curr = 0;
        for(int j = 0; j < m; j++) {
            for(int i = 0; i < n; i++) curr += grid[i][j];
            if(2 * curr == sum) return true;
        }
        return false;
    }
};