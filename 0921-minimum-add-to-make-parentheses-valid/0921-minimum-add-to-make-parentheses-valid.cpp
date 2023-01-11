class Solution {
public:
	int minAddToMakeValid(string &str) {
		int ans = 0;
		stack <char> s;
		for (auto x : str) {
			if (x == '(') s.push(x);
			else {
				if (s.empty()) ans++;
				else s.pop();
			}
		}
		ans += s.size();
		return ans;
	}
};