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
			power[i] = (power[i - 1] * base) % mod;
		}
	}

	int substr(int l, int r) {
		ll ans = suffix[l] - (suffix[r + 1] * power[r - l + 1]);
		return ((ans % mod) + mod) % mod;
	}
};

class Solution {
public:
	int strStr(string haystack, string needle) {
		SingleHash h = SingleHash(haystack);
		SingleHash k = SingleHash(needle);

		int n = haystack.size(),
		    m = needle.size(),
		    req = k.substr(0, m - 1);
		for (int i = 0; i <= n - m; i++) {
			if (req == h.substr(i, i + m - 1)) return i;
		}
		return -1;
	}
};