class Solution {
public:
    int maxValueOfCoinsUtils(int i, int k, vector <vector<int>> &piles, vector <vector <int>> &dp) {
        if(i == -1) {
            if(k) return -1e9;
            return 0;
        } else if(k == 0) return 0;
        else if(dp[i][k] != -1) return dp[i][k]; 
            
        int ans = 0, sum = 0;
        for(int j = 0; j <= min(k, (int)piles[i].size()); j++) {
            if(j) sum += piles[i][j - 1];
            int curr = sum + maxValueOfCoinsUtils(i - 1, k - j, piles, dp);
            ans = max(ans, curr);
        }
        
        return dp[i][k] = ans;
    }
    
    int maxValueOfCoins(vector<vector<int>> &piles, int k) {
        int n = piles.size();
        vector <vector <int>> dp(n, vector <int> (k + 1, -1));
        return maxValueOfCoinsUtils(n - 1, k, piles, dp);
    }
};