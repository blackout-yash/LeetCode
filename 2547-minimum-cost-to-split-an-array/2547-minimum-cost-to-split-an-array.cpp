#define ll long long
class Solution {
public:
    int minCost(vector <int> &nums, int k) {
        int n = nums.size();
        vector <ll> dp(n + 1, 1e18);
        dp[0] = 0;
        for(int i = 1; i <= n; i++) {
            ll curr = 0;
            vector <ll> m(n);
            for(int j = i - 1; j >= 0; j--) {
                m[nums[j]]++;
                if(m[nums[j]] == 2) curr += 2;
                else if(m[nums[j]] > 1) curr++;
                dp[i] = min(dp[i], k + curr + dp[j]);
            }
        }
        return dp[n];
    }
};