#define ll long long
class Solution {
public:
    long long maxScore(vector<int> &nums, int x) {
        int n = nums.size();
        vector <vector <ll>> dp(n, vector <ll> (2, -x));
        for(int i = 0; i < n; i++) {
            if(i == 0) {
                if(nums[i] & 1) dp[i][1] = nums[i];
                else dp[i][0] = nums[i];
            } else if(nums[i] & 1) {
                dp[i][0] = dp[i - 1][0];
                dp[i][1] = max(dp[i - 1][0] - x, dp[i - 1][1]) + nums[i];
            } else {
                dp[i][0] = max(dp[i - 1][0], dp[i - 1][1] - x) + nums[i];
                dp[i][1] = dp[i - 1][1];
            }
        }
        return max(dp[n - 1][0], dp[n - 1][1]);
    }
};