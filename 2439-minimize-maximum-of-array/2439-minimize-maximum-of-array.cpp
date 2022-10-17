#define ll long long
class Solution {
public:
	bool isPossible(ll tar, vector <int> &nums) {
		ll n = nums.size(), prev = 0;
		for (int i = n - 1; i >= 0; i--) {
			if (nums[i] > tar) prev += (nums[i] - tar);
			else prev -= min(prev, 1ll * (tar - nums[i]));
		} 
		if (prev) return 0;
		return 1;
	}

	int minimizeArrayValue(vector<int> &nums) {
		ll low = 0, high = 1e9 + 10, ans = high;
		while (low <= high) {
			ll mid = low + (high - low) / 2;
			if (isPossible(mid, nums)) {
				ans = mid;
				high = mid - 1;
			} else low = mid + 1;
		}
		return ans;
	}
};