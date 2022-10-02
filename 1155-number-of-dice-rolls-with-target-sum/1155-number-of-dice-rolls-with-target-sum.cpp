#define ll long long
class Solution {
public:
	ll modAdd(ll a, ll b, ll m = 1e9 + 7) {a %= m; b %= m; return (((a + b) % m) + m) % m;}

	int numRollsToTarget(int n, int k, int target) {
		vector <vector<ll>> dp(n + 1, vector<ll> (target + 1));
		dp[0][0] = 1;
		for (int i = 1; i <= n; i++) {
			for (int j = 0; j <= target; j++) {
				for (int face = 1; face <= k; face++) {
					if (j >= face) dp[i][j] = modAdd(dp[i][j], dp[i - 1][j - face]);
				}
			}
		}
		return dp[n][target];
	}
};