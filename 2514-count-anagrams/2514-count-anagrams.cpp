#define ll long long
const int n = 1e5;
vector <ll> fact(n + 1);
class Solution {
public:
	ll mul(ll a, ll b, ll m = 1e9 + 7) {a %= m; b %= m; return (((a * b) % m) + m) % m;}

	ll gcdExtended(ll a, ll b, ll *x, ll *y) {
		if (a == 0) {
			*x = 0, *y = 1;
			return b;
		}

		ll x1, y1;
		ll gcd = gcdExtended(b % a, a, &x1, &y1);

		*x = y1 - (b / a) * x1;
		*y = x1;

		return gcd;
	}

	ll modInverse(ll b, ll m = 1e9 + 7) {
		ll x, y;
		ll g = gcdExtended(b, m, &x, &y);

		if (g != 1) return -1;
		return (x % m + m) % m;
	}

	ll modDiv(ll a, ll b, ll m = 1e9 + 7) {
		a = a % m;
		ll inv = modInverse(b, m);

		// Division not defined
		if (inv == -1) return -1;
		return (inv * a) % m;
	}

	void preCompute() {
		fact[0] = 1;
		for (int i = 1; i <= 1e5; i++) fact[i] = mul(i, fact[i - 1]);
	}

	int countAnagrams(string str) {
		preCompute();
		map <char, int> m;
		ll ans = 1, n = str.size();
		for (int i = 0; i < n; i++) {
			if (str[i] != ' ') m[str[i]]++;
			if (i + 1 == n || str[i] == ' ') {
				ll size = 0, num, denom = 1;
				for (auto x : m) {
					size += x.second;
					denom = mul(denom, fact[x.second]);
				}
				num = fact[size];
				ans = mul(ans, modDiv(num, denom));
				m.clear();
			}
		}
		return ans;
	}
};