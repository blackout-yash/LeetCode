class Solution {
public:
	string removeKdigits(string num, int k) {
		string ans;
		int n = num.size();
		for (int i = 0; i <= n; i++) {
			while (ans.size() && k && (i == n || ans.back() > num[i])) {
				k--;
				ans.pop_back();
			}

			if (i == n) continue;
			else if (ans.size()) ans.push_back(num[i]);
			else if (num[i] != '0') ans.push_back(num[i]);
		}

		if (ans.empty()) ans.push_back('0');
		return ans;
	}
};