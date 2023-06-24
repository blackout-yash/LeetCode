class Solution {
public:
    int sum(int diff, int n, vector <int> &rod, vector <vector <int>> &dp) {
        if(n == -1) {
            if(diff) return -1e9;
            return 0;
        } else if(dp[n][5000 + diff] != -1) return dp[n][5000 + diff];
        
        int ans1 = rod[n] + sum(diff + rod[n], n - 1, rod, dp),
            ans2 = rod[n] + sum(diff - rod[n], n - 1, rod, dp),
            ans3 = sum(diff, n - 1, rod, dp);        
        
        return dp[n][5000 + diff] = max({ans1, ans2, ans3});
    }
    
    int tallestBillboard(vector <int> &rods) {
        int n = rods.size();
        vector <vector <int>> dp(n, vector <int> (10001, -1));
        int ans = sum(0, n - 1, rods, dp);
        return ans / 2;
    }
};