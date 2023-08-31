class Solution {
public:
    int minTaps(int n, vector <int> &ranges) {
        vector <int> dp(n + 1, 1e9);
        for(int i = 0; i <= n; i++) {
            if(ranges[i] == 0) continue;
            int l = i - ranges[i], r = i + ranges[i];
            for(int j = max(0, l); j <= min(n, r); j++) {
                if(l <= 0) dp[j] = 1;
                else dp[j] = min(dp[j], dp[l] + 1);
            }
        }
        if(dp[n] == 1e9) return -1;
        return dp[n];
    }
};