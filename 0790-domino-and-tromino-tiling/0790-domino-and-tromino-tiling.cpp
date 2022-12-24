#define ll long long
class Solution {
public:
	ll add(ll a, ll b, ll m = 1e9 + 7) {return (((a + b) % m) + m) % m;}

	int numTilings(int n) {
		vector <vector<ll>> dp(n + 1, vector<ll> (2));
		dp[0][1] = 1;
		for (int i = 1; i <= n; i++) {
			if (i > 1) {
				dp[i][0] = dp[i - 2][0];
				dp[i][0] = add(dp[i][0], dp[i - 2][1]);
			}

			dp[i][1] = dp[i - 1][1];
			dp[i][1] = add(dp[i][1], (2 * dp[i - 1][0]));
			if (i > 1) {
				dp[i][1] = add(dp[i][1], dp[i - 2][1]);
				dp[i][1] = add(dp[i][1], (2 * dp[i - 2][0]));
			}
		}
		return dp[n][1];
	}
};