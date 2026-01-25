class Solution {
public:
    int minimumDifference(vector <int> &nums, int k) {
        int ans = INT_MAX;
        sort(begin(nums), end(nums));
        for(int i = k - 1; i < nums.size(); i++) ans = min(ans, nums[i] - nums[i - k + 1]);
        return ans;
    }
};