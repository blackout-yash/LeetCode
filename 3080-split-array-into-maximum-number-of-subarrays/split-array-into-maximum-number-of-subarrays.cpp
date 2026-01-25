class Solution {
public:
    int maxSubarrays(vector <int> &nums) {
        int mn = nums[0], curr = nums[0];
        for(auto x: nums) {
            curr &= x;
            mn = min(mn, curr);
        }

        if(mn) return 1;

        int cnt = 0;
        curr = nums[0];
        for(auto x: nums) {
            curr &= x;
            if(curr == mn) {
                cnt++;
                curr = INT_MAX;
            }
        }
        return cnt;
    }
};