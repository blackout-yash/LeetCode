class Solution {
public:
    int maxSubarraySumCircular(vector <int> &nums) {
        int n = nums.size(), ans = -1e9, curr = 0;
        vector <int> prefix(n + 2), suffix(n + 2);
        for(int i = 1; i <= n; i++) {
            curr += nums[i - 1];
            if(i == 1) prefix[i] = curr;
            else prefix[i] = max(prefix[i - 1], curr);
        }
        
        curr = 0;
        for(int i = n; i >= 1; i--) {
            curr += nums[i - 1];
            if(i == n) suffix[i] = curr;
            else suffix[i] = max(suffix[i + 1], curr);
        }
        
        curr = 0;
        for(int i = 1; i <= n; i++) {
            curr += nums[i - 1];
            ans = max(ans, curr);
            curr = max(0, curr);
            
            ans = max(ans, prefix[i - 1] + suffix[i]);
        }
        return ans;
    }
};