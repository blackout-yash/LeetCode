class Solution {
public:
	int pal[200][200], dp[200][200][200];

	void preCompute(int n, int k, string &s) {
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				int l = i, r = j, ans = 0;
				while (l <= r) {
					if (s[l] != s[r]) ans++;
					l++; r--;
				} pal[i][j] = ans;
			}
		}
        
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                for(int ind = 0; ind < k; ind++) dp[i][j][ind] = -1;
            }
        }
	}

	int palindromePartition(int i, int j, int k, int n, string &s) {
		if (j == n) {
			if (k) return 1e9;
			return pal[i][j - 1];
		} else if(dp[i][j][k] != -1) return dp[i][j][k];

		int ans1 = 1e9;
		if (k && j + 1 != n) ans1 = pal[i][j] + palindromePartition(j + 1, j + 1, k - 1, n, s);
		int ans2 = palindromePartition(i, j + 1, k, n, s);
        
		return dp[i][j][k] = min(ans1, ans2);
	}

	int palindromePartition(string s, int k) {
		int n = s.size();
		preCompute(n, k, s);
        
		int ans = palindromePartition(0, 0, k - 1, n, s);

		return ans;
	}
};