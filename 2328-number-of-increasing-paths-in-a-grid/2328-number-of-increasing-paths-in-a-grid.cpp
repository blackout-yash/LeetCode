#define ppi pair <int, pair <int, int>>
class Solution {
public:
    vector <vector <int>> move = {{0, -1}, {1, 0}, {0, 1}, {-1, 0}};
    
    int sum(int a, int b, int m = 1e9 + 7) {a %= m; b %= m; return (((a + b) % m) + m) % m;}
    
    bool isValid(int i, int j, int n, int m) {
        return i >= 0 && i < n && j >= 0 && j < m;
    }
    
    int countPaths(vector<vector<int>>& grid) {
        vector <ppi> arr, store;
        int n = grid.size(), m = grid[0].size();
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) arr.push_back({grid[i][j], {i, j}});
        }
        sort(begin(arr), end(arr));
        
        int prev = arr[0].first, ans = 0;
        vector <vector <int>> dp(n, vector <int> (m, 1));
        for(int i = 0; i < n * m; i++) {
            store.push_back(arr[i]);
            if(i + 1 == n * m || prev != arr[i + 1].first) {
                for(auto x: store) {
                    int it1 = x.second.first,
                        it2 = x.second.second;
                    for(auto y: move) {
                        int it3 = it1 + y[0],
                            it4 = it2 + y[1];
                        if(!isValid(it3, it4, n, m)) {}
                        else if(grid[it3][it4] < grid[it1][it2]) dp[it1][it2] = sum(dp[it1][it2], dp[it3][it4]);
                    }
                    ans = sum(ans, dp[it1][it2]);
                }
                if(i + 1 == n * m) {}
                else {
                    store.clear();
                    prev = arr[i + 1].first;
                }
            } 
        }

        return ans;
    }
};