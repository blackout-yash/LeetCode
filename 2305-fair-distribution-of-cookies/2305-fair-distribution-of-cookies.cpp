class Solution {
public:
	void distributeCookies(int n, int &ans, vector <int> &store, vector <int> &cookies) {
		if (n == -1) {
			ans = min(ans, *max_element(store.begin(), store.end()));
			return;
		}

		for (auto &x : store) {
			x += cookies[n];
			distributeCookies(n - 1, ans, store, cookies);
			x -= cookies[n];
		}
	}

	int distributeCookies(vector<int> &cookies, int k) {
		int n = cookies.size();
		vector <int> store(k);

		int ans = 1e9;
		distributeCookies(n - 1, ans, store, cookies);

		return ans;
	}
};