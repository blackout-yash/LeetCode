class Solution {
public:
    int minOperations(vector <int> &nums, int x) {
    int total = accumulate(nums.begin(), nums.end(), 0);
    int target = total - x;
    if (target < 0) {
        return -1;
    }
    if (target == 0) {
        return nums.size();
    }
    unordered_map<int, int> window;
    int window_sum = 0;
    int maxLen = 0;
    for (int i = 0; i < nums.size(); ++i) {
        window_sum += nums[i];
        if (window_sum == target) {
            maxLen = i + 1;
        }
        if (window.count(window_sum - target)) {
            maxLen = max(maxLen, i - window[window_sum - target]);
        }
        if (!window.count(window_sum)) {
            window[window_sum] = i;
        }
    }
    return maxLen == 0 ? -1 : nums.size() - maxLen;
    }
};