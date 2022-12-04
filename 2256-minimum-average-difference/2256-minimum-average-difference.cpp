#define ll long long
class Solution {
public:
    int minimumAverageDifference(vector<int>& nums) {
        ll n = nums.size(), start = 0, end = 0, min = 1e9, index = 0, cnt1 = 0, cnt2 = n;
        for(auto x: nums) end += x;
        for(int i = 0; i < n; i++) {
            start += nums[i];
            end -= nums[i];
            cnt1++; cnt2--;
            ll alpha = start / cnt1, beta = 0;
            if(cnt2) beta = end / cnt2;
            if(abs(alpha - beta) < min) {
                min = abs(alpha - beta);
                index = i;
            }
        }
        return index;
    }
};