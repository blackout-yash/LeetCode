class Solution {
public:
	bool checkSubarraySum(vector <int> &nums, int k) {
		map <int, int> m; m[nums[0] % k] = 0;
		int sum = nums[0], n = nums.size();
		for (int i = 1; i < n; i++) {
			sum += nums[i];
			sum %= k;
			if(!sum || (m.count(sum) && i - m[sum] > 1)) return true;
			else if(!m.count(sum)) m[sum] = i;
		}
		return false;
	}
};