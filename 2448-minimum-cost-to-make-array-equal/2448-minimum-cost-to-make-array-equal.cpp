#define ll long long
class Solution {
public:
	long long minCost(vector<int>& nums, vector<int>& cost) {
		ll n = nums.size(), range = 0, sum = 0, pro = 0;
		vector <pair<int, int>> temp;
		for (int i = 0; i < n; i++) {
			sum += cost[i];
			pro += (1ll * nums[i] * cost[i]);
            range = max(range, 1ll * nums[i]);
			temp.push_back({nums[i], cost[i]});
		} sort(temp.begin(), temp.end());

		ll currSum = 0, currPro = 0, j = 0, ans = 1e18;
		for (int i = 0; i <= range; i++) {
			while (true) {
				if (j + 1 == n) break;
				else if (temp[j].first > i) break;
				currSum += temp[j].second;
				currPro += (1ll * temp[j].first * temp[j].second);
				j++;
			}
			ans = min(ans, (pro - (i * sum)) - (2 * (currPro - (i * currSum))));
		}
		return ans;
	}
};