#define ll long long
class Solution {
public:
    long long zeroFilledSubarray(vector<int>& nums) {
        ll ans = 0, cnt = 0, n = nums.size();
        for(int i = 0; i < n; i++) {
            if(!nums[i]) cnt++;
            if(nums[i] || i + 1 == n) ans += (cnt * (cnt + 1)) / 2, cnt = 0;
        }
        return ans;
    }
};