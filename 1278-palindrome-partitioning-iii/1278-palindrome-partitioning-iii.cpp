class Solution {
public:
	int pal[200][200];
	void preCompute(int n, string &s) {
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				int l = i, r = j, ans = 0;
				while (l <= r) {
					if (s[l] != s[r]) ans++;
					l++; r--;
				} pal[i][j] = ans;
			}
		}
	}

	int palindromePartition(string s, int k) {
		int n = s.size();
		preCompute(n, s);

		vector <vector<int>> dp(n, vector<int> (k, 1e9));
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < min(k, i + 1); j++) {
                // if there is no partition                 
                if(!j) {
                    dp[i][j] = pal[0][i];
                    continue;
                }
                
                // this loop only runs when there is partition
                // the ind can't run till 0 
                // if take ind as 0, then, we can't make j paritions in array                
				for (int ind = i; ind >= 1; ind--) {
					int ans = pal[ind][i] + dp[ind - 1][j - 1];
				    dp[i][j] = min(dp[i][j], ans);
				}
			}
		}
        
		return dp[n - 1][k - 1];
	}
};