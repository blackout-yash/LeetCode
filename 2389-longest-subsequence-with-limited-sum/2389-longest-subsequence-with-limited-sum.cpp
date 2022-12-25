class Solution {
public:
	vector<int> answerQueries(vector<int>& nums, vector<int>& queries) {
		sort(nums.begin(), nums.end());
		int n = nums.size(), m = queries.size();
		for (int i = 1; i < n; i++) nums[i] += nums[i - 1];

		vector <int> ans;
		for (auto x : queries) {
			int ind = upper_bound(nums.begin(), nums.end(), x) - nums.begin();
			ans.push_back(ind);
		}
		return ans;
	}
};