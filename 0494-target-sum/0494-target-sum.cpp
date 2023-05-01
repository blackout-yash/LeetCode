class Solution {
public:
    int func(vector <int> &nums, int target, int n, int sum, int max, vector <vector <int>> &dp){
        if(n < 0 && sum == target) return 1;
        if(n < 0) return 0;
        if(dp[n][max + sum] !=- 1) return dp[n][max + sum];

        int plus = 0, minus = 0;
        plus = func(nums, target, n - 1, sum + nums[n], max, dp);
        minus = func(nums, target, n - 1, sum - nums[n], max, dp);
        return dp[n][max + sum] = plus + minus;
    }
    
    int findTargetSumWays(vector <int> &nums, int target) {
        int n = nums.size();
        int sum = 0, add = 0;
        for(int i = 0; i < n; i++) add += nums[i];
        
        vector <vector <int>> dp(n, vector <int> ((2 * add) + 1, -1));
        return func(nums, target, n - 1, sum, add, dp);
    }
};