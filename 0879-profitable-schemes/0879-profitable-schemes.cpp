class Solution {
public:
    int sum(int a, int b, int m = 1e9 + 7) {a %= m; b %= m; return (a + b) % m;}
    
    int profitableSchemes(int i, int j, int k, int n, int minProfit, vector <int> &group, vector <int> &profit, vector <vector <vector <int>>> &dp) {
        if(j > n) return 0;
        else if(i == group.size()) {
            if(k == minProfit) return 1;
            return 0;
        } else if(dp[i][j][k] != -1) return dp[i][j][k];
            
        int take = profitableSchemes(i + 1, j + group[i], min(k + profit[i], minProfit), n, minProfit, group, profit, dp);
        int notTake = profitableSchemes(i + 1, j, k, n, minProfit, group, profit, dp);
        
        return dp[i][j][k] = sum(take, notTake);
    }
    
    int profitableSchemes(int n, int minProfit, vector <int> &group, vector <int> &profit) {
        vector <vector <vector <int>>> dp(200, vector <vector <int>> (200, vector <int> (200, -1)));
        return profitableSchemes(0, 0, 0, n, minProfit, group, profit, dp);
    }
};