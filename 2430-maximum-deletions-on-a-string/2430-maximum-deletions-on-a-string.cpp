#define ll long long
class SingleHash {
public:
	int mod = 1e9 + 7, base = 31;
	vector <ll> suffix, power;

	SingleHash(string &s) {
		int n = s.length();
		suffix.assign(n + 1, 0);
		power.assign(n + 1, 0);

		power[0] = 1;
		power[1] = base;
		for (int i = n - 1; i >= 0; --i) {
			suffix[i] = (s[i] + (suffix[i + 1] * base)) % mod;
		}

		for (int i = 2; i <= n; ++i) {
			power[i] = (power[i - 1] * power[1]) % mod;
		}
	}

	int substr(int l, int r) {
		ll ans = suffix[l] - (suffix[r + 1] * power[r - l + 1]);
		return ((ans % mod) + mod) % mod;
	}
};

class Solution {
public:
	int deleteString(string s) {
		SingleHash h = SingleHash(s);
                
		int n = s.size(), ans = 0;
		vector <int> dp(n);
		for (int i = 0; i < n; i++) {
			int j = i, mid = i + 1, k = i + 1;
			while (true) {
				if (j == -1 || k == n) break;
				else if (h.substr(j, i) == h.substr(mid, k)) {
					if (!j) dp[i] = max(dp[i], 1);
					else if (dp[j - 1]) dp[i] = max(dp[i], 1 + dp[j - 1]);
				} j--; k++;
			} ans = max(ans, dp[i] + 1);
		}
		return ans;
	}
};