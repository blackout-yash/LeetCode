class Solution {
public:
    int mincostTickets(vector<int> &days, vector<int> &costs) {
        int n = days.size();
        vector <vector <int>> dp(n + 1, vector <int> (3, 1e9));
        dp[0][0] = dp[0][1] = dp[0][2] = 0;
        for(int i = 1; i <= n; i++) {
            for(int j = 0; j < 3; j++) {
                int day = (j == 0) ? 1 : (j == 1) ? 7 : 30;
                for(int k = i; k >= 1; k--) {
                    if(days[i - 1] - days[k - 1] >= day) break;
                    dp[i][j] = min(dp[i][j], costs[j] + min({dp[k - 1][0], dp[k - 1][1], dp[k - 1][2]}));
                }
            }
        }
        return min({dp[n][0], dp[n][1], dp[n][2]});
    }
};