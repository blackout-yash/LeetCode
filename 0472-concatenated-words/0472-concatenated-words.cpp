class Solution {
public:
	map <string, bool> m;
	bool isPossible(int i, int n, string &curr, string &s, vector <vector<int>> &dp) {
		int j = curr.size();
		if (i == n) return 1;
		else if (dp[i][j] != -1) return dp[i][j];

		bool ans = 0;
		for (int k = i; k < n; k++) {
			curr.push_back(s[k]);
			if (m.count(curr) && curr.size() != n) {
				string temp;
				ans |= isPossible(k + 1, n, temp, s, dp);
			}
		}

		while (curr.size() != j) curr.pop_back();
		return dp[i][j] = ans;
	}

	vector <string> findAllConcatenatedWordsInADict(vector<string>& words) {
		for (auto x : words) m[x] = 1;

		vector <string> ans;
		for (auto x : words) {
			string temp;
			int n = x.size();
			vector <vector<int>> dp(n, vector<int> (n + 1, -1));
			if (isPossible(0, n, temp, x, dp)) ans.push_back(x);
		}
		return ans;
	}
};