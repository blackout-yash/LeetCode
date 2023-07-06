class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int j = 0, curr = 0, ans = 1e9, n = nums.size();
        for(int i = 0; i < n; i++) {
            curr += nums[i];
            while(true) {
                if(curr >= target) ans = min(ans, i - j + 1);
                if(curr <= target) break;
                curr -= nums[j++];
            } 
        }
        if(ans == 1e9) return 0;
        return ans;
    }
};