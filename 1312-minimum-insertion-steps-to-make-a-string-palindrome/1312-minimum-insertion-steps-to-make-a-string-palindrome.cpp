class Solution {
public:
    int minInsertions(string s) {
        string str1 = s, str2 = s;
        reverse(str2.begin(), str2.end());

        int n = str1.size(), m = str2.size();
        vector <int> dp(m);
        for (int i = 0; i < m; i++) {
            vector <int> curr(m);
            for (int j = 0; j < m; j++) {
                if (str1[i] == str2[j]) {
                    int ans = 1;
                    if (i && j) ans += dp[j - 1];
                    curr[j] = ans;
                } else {
                    int ans1 = 0;
                    if (i) ans1 = dp[j];
                    int ans2 = 0;
                    if (j) ans2 = curr[j - 1];
                    curr[j] = max(ans1, ans2);
                }
            }
            dp = curr;
        }

        return n - dp[m - 1];
    }
};