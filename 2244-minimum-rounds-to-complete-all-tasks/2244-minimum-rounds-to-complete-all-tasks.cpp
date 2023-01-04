class Solution {
public:
	int minimumRounds(vector <int> &tasks) {
		map <int, int> m;
		for (auto x : tasks) m[x]++;

		int ans = 0;
		for (auto x : m) {
			int freq = x.second,
			    rem = (freq % 3);
			if (rem == 0) ans += freq / 3;
			else if (rem == 1) {
				if (freq == 1) return -1;
				else ans += (freq / 3) + 1;
			} else ans += (freq / 3) + 1;
		}
		return ans;
	}
};