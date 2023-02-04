class Solution {
public:
	int largestRectangleArea(vector<int> &heights) {
		stack <int> s;
        int ans = 0, n = heights.size();
		for (int i = 0; i <= n; i++) {
			while (s.size() && (i == n || heights[s.top()] >= heights[i])) {
				int height = heights[s.top()],
				    width = i;
				s.pop();
				if (s.size()) width = (i - s.top() - 1);
				ans = max(ans, height * width);
			} s.push(i);
		}
		return ans;
	}
};