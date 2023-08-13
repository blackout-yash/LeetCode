class Solution {
public:
    bool validPartition(vector <int> &nums) {
        int n = nums.size();
        vector <int> dp(n);
        for(int i = 1; i < n; i++) {
            bool ans1 = 0, ans2 = 0;
            if(nums[i] == nums[i - 1]) {
                if(i >= 2) ans1 = dp[i - 2];
                else ans1 = true;
            }
            
            if(i >= 2) {
                if((nums[i] == nums[i - 1] && nums[i] == nums[i - 2]) ||
                   (nums[i] - nums[i - 1] == 1 && nums[i - 1] - nums[i - 2] == 1)) {
                    if(i >= 3) ans2 = dp[i - 3];
                    else ans2 = true;
                } 
            }
            
            dp[i] = (ans1 | ans2);
        }
        return dp[n - 1];
    }
};