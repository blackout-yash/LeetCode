class Solution {
public:
	int findJudge(int n, vector<vector<int>> &trust) {
		vector <int> isTrust(n + 1), cnt(n + 1);
		for (auto x : trust) {
			isTrust[x[1]]++;
			cnt[x[0]]++;
		}
        
		int ans = -1, count = 0;
		for (int i = 1; i <= n; i++) {
			if (!cnt[i] && isTrust[i] + 1 == n) {
				ans = i;
				count++;
			}
		}
		if (count == 1) return ans;
		return -1;
	}
};