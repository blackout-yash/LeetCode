#define ll long long
class Solution {
public:
	long long subArrayRanges(vector <int> &nums) {
		stack <int> min, max;
		ll plus = 0, minus = 0, n = nums.size();
		for (int i = 0; i <= n; i++) {
			while (min.size() && (i == n || nums[min.top()] >= nums[i])) {
				ll num = nums[min.top()],
				   left = min.top() + 1,
				   right = i - min.top();
				min.pop();
				if (min.size()) left = left - min.top() - 1;
				minus += (left * right * num);
			}
			while (max.size() && (i == n || nums[max.top()] <= nums[i])) {
				ll num = nums[max.top()],
				   left = max.top() + 1,
				   right = i - max.top();
				max.pop();
				if (max.size()) left = left - max.top() - 1;
				plus += (left * right * num);
			}
			min.push(i);
			max.push(i);
		}
		return plus - minus;
	}
};