class Solution {
public:
	map <string, bool> m;
	bool isPossible(string &s) {
		int n = s.size();
		vector <int> dp(n);
		for (int i = n - 1; i >= 0; i--) {
			string curr;
			for (int j = i; j < n; j++) {
				curr.push_back(s[j]);
				if (m.count(curr) && curr.size() != n) {
					if (j + 1 >= n) dp[i] = 1;
					else dp[i] = dp[j + 1];
				}
                if(dp[i]) break;
			}
		}
        
		return dp[0];
	}

	vector <string> findAllConcatenatedWordsInADict(vector<string>& words) {
		for (auto x : words) m[x] = 1;

		vector <string> ans;
		for (auto x : words) {
			if (isPossible(x)) ans.push_back(x);
		}
		return ans;
	}
};