class Solution {
public:
	int minDistanceUtil(int i, int j, string &word1, string &word2, vector <vector <int>> &dp) {
		if (i == -1) return j + 1;
		else if (j == -1) return i + 1;
        else if(dp[i][j] != -1) return dp[i][j];

		int ans = minDistanceUtil(i - 1, j - 1, word1, word2, dp);

		int ans1 = ans + (word1[i] != word2[j]);
		int ans2 = 1 + minDistanceUtil(i - 1, j, word1, word2, dp);
		int ans3 = 1 + minDistanceUtil(i, j - 1, word1, word2, dp);

		return dp[i][j] = min({ans1, ans2, ans3});
	}

	int minDistance(string word1, string word2) {
		int n = word1.size(),
		    m = word2.size();
        vector <vector <int>> dp(n, vector <int> (m, -1));
		return minDistanceUtil(n - 1, m - 1, word1, word2, dp);
	}
};