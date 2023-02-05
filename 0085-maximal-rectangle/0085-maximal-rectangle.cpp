class Solution {
public:
	int maximalRectangleUtil(int n, vector <int> &height) {
		int ans = 0;
		stack <int> s;
		for (int i = 0; i <= n; i++) {
			while (s.size() && (i == n || height[s.top()] > height[i])) {
				int num = height[s.top()],
				    left = s.top(),
				    right = i - s.top();
				s.pop();
				if (s.size()) left = left - s.top() - 1;
				int curr = (left + right) * num;
				ans = max(ans, curr);
			} s.push(i);
		}
		return ans;
	}

	int maximalRectangle(vector<vector<char>>& matrix) {
		int ans = 0, n = matrix.size(), m = matrix[0].size();
		vector <int> height(m);
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (matrix[i][j] == '1') height[j] = 1 + height[j];
				else height[j] = 0;
			}
			int curr = maximalRectangleUtil(m, height);
			ans = max(ans, curr);
		}
		return ans;
	}
};