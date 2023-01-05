class Solution {
public:
	int findMinArrowShots(vector<vector<int>>& p) {
		sort(p.begin(), p.end());
		int ans = 1, r = p[0][1];
		for (auto point : p) {
			if (point[0] > r) {
				ans++;
				r = point[1];
			}
			r = min(point[1], r);
		}
		return ans;
	}
};