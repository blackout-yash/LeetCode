class Solution {
public:
	string removeKdigits(string num, int k) {
		stack <char> s;
		int n = num.size();
		for (int i = 0; i <= n; i++) {
			while (s.size() && k && (i == n || s.top() > num[i])) {
				k--;
				s.pop();
			}
            if(i == n) continue;
			else if (s.size()) s.push(num[i]);
			else if (num[i] != '0') s.push(num[i]);
		}

		string ans;
		while (s.size()) {
			ans.push_back(s.top());
			s.pop();
		}
		reverse(ans.begin(), ans.end());
		if (ans.empty()) ans.push_back('0');
		return ans;
	}
};