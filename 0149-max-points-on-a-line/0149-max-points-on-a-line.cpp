#define ll long long
class Solution {
public:
	bool isStr(int i, int j, int k, vector<vector<int>> &points) {
		ll x1 = points[i][0], y1 = points[i][1],
		   x2 = points[j][0], y2 = points[j][1],
		   x3 = points[k][0], y3 = points[k][1];
		ll dis1 = ((x2 - x1) * (x2 - x1)) + ((y2 - y1) * (y2 - y1)),
		   dis2 = ((x3 - x2) * (x3 - x2)) + ((y3 - y2) * (y3 - y2)),
		   dis3 = ((x3 - x1) * (x3 - x1)) + ((y3 - y1) * (y3 - y1));

		ll temp1 = 4 * dis1 * dis2,
		   temp2 = dis3 - (dis1 + dis2),
		   temp3 = temp2 * temp2;

		return (temp1 == temp3);
	}

	int maxPoints(vector<vector<int>> &points) {
		int n = points.size(), ans = 2;
		if (n == 1) return 1;
		for (int i = 0; i < n; i++) {
			for (int j = i + 1; j < n; j++) {
				int cnt = 2;
				for (int k = j + 1; k < n; k++) {
					if (isStr(i, j, k, points)) cnt++;
					else if (isStr(i, k, j, points)) cnt++;
					else if (isStr(j, i, k, points)) cnt++;
					else if (isStr(j, k, i, points)) cnt++;
					else if (isStr(k, i, j, points)) cnt++;
					else if (isStr(k, j, i, points)) cnt++;
				} ans = max(ans, cnt);
			}
		}
		return ans;
	}
};