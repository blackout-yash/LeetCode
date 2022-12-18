#define ll long long
const ll range = 1e5 + 100;
bitset < range + 5 > b;
vector <ll> prime;

void sieve() {
	b.set();

	b[0] = b[1] = 0;

	for (ll i = 2; i <= range; i++) {
		if (b[i]) {
			prime.push_back(i);
			for (ll j = i * i; j <= range; j += i) {
				b[j] = 0;
			}
		}
	}
}

class Solution {
public:
	int smallestValue(int n) {
		sieve();
		int ans = n;
		while (true) {
			if (n == 1) break;
            else if(binary_search(prime.begin(), prime.end(), n)) break;
            
			int temp = 0, start = n;
			for (auto x : prime) {
				if (n == 1) break;
				while (true) {
					if (n % x) break;
					temp += x;
					n /= x;
				}
			}

			ans = min(ans, temp);
            if(start == temp) break;
            else n = temp;
		}
		return ans;
	}
};