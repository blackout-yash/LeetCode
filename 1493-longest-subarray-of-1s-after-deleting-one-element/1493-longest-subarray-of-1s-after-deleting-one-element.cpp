class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int ans = 0, one = 0, zero = 0, prev = 0;
        for(auto x: nums) {
            if(x) one++, zero = 0;
            else zero++;
            
            if(zero == 1) prev = one, one = 0;
            else if(zero > 1) prev = 0;
            ans = max(ans, one + prev);
        }
        return min((int)nums.size() - 1, ans);
    }
};