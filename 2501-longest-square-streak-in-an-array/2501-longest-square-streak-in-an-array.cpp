class Solution {
public:
	int longestSquareStreak(vector<int>& nums) {
		map <int, int> m;
		for (auto x : nums) m[x] = 1;

		long long ans = 1;
		for (auto x : m) {
			long long temp = 1, prev = x.first;
			while (true) {
                if(prev > 1e5) break;
				prev *= prev;
				if (m.count(prev)) temp++;
				else break;
			}
			ans = max(ans, temp);
		}
        if(ans < 2) ans = -1;
		return ans;
	}
};