class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        int range = 5e4, n = 1e5;
        vector <int> dp(n + 1);
        sort(begin(intervals), end(intervals));
        
        int j = 0, m = intervals.size();
        for(int i = 0; i <= n; i++) {
            if(i) dp[i] = max(dp[i], dp[i - 1]);
            while(j < m) {
                int ans = 1 + dp[i], l = intervals[j][0] + range, r = intervals[j][1] + range;
                if(l != i) break;
                dp[r] = max(dp[r], ans);
                j++;
            }
        }
        return m - dp[n];
    }
};