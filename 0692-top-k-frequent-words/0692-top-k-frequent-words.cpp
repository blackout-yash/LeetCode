class Solution {
public:
	vector<string> topKFrequent(vector<string>& words, int k) {
		map <string, int> m;
		for (auto x : words) m[x]++;

		set <pair<int, string>> s;
		for (auto x : m) s.insert({ -x.second, x.first});

		vector <string> ans;
		for (auto x : s) {
			if (k) ans.push_back(x.second), k--;
			else break;
		}

		return ans;
	}
};