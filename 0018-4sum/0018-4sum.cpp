#define ll long long
class Solution {
public:
	vector<vector<int>> fourSum(vector<int>& nums, int target) {
		vector<vector<int>>result;
		if (nums.size() <= 3) return result;
		sort(nums.begin(), nums.end());

		for (int i = 0; i < nums.size() - 3; i++) {
			if (i > 0 && nums[i] == nums[i - 1]) continue;

			for (int j = i + 1; j < nums.size() - 2; j++) {
				if (j > i + 1 && nums[j] == nums[j - 1]) continue;

				ll temp = target - 1ll* (nums[i] + nums[j]);
				int low = j + 1, high = nums.size() - 1;
				while (low < high) {
					if (temp == nums[low] + nums[high]) {
						vector<int> ans;
						ans.push_back(nums[i]);
						ans.push_back(nums[j]);
						ans.push_back(nums[low]);
						ans.push_back(nums[high]);
						result.push_back(ans);
						while (low < high && nums[low] == nums[low + 1]) low++;
						while (low < high && nums[high] == nums[high - 1]) high--;
						low++;
						high--;
					}
					else if (temp > nums[low] + nums[high]) low++;
					else high--;
				}
			}
		}
		return result;
	}
};