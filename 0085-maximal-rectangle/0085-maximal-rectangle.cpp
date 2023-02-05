class Solution {
public:
	int maximalRectangleUtil(int n, vector <int> &arr) {
		int ans = 0;
		stack <int> s;
		for (int i = 0; i <= n; i++) {
			while (s.size() && (i == n || arr[s.top()] > arr[i])) {
				int num = arr[s.top()],
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
		vector <int> prev(m);
		for (int i = 0; i < n; i++) {
			vector <int> temp(m);
			for (int j = 0; j < m; j++) {
				if (matrix[i][j] == '1') temp[j] = 1 + prev[j];
			}
			int curr = maximalRectangleUtil(m, temp);
			ans = max(ans, curr);
			prev = temp;
		}
		return ans;
	}
};