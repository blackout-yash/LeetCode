class Solution {
public:
	int sumSubarrayMins(vector <int> &arr) {
		stack <int> s;
		int n = arr.size(), ans = 0, mod = 1e9 + 7;
		for (int i = 0; i <= n; i++) {
			while (s.size() && (i == n || arr[s.top()] >= arr[i])) {
				int num = arr[s.top()],
				    left = s.top() + 1,
				    right = i - s.top();
				s.pop();
				if (s.size()) left = left - s.top() - 1;
				long curr = 1l * left * right * num;
				ans = ((long)ans + curr) % mod;
			}
			s.push(i);
		}
		return ans;
	}
};