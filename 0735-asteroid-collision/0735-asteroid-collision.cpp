class Solution {
public:
	vector<int> asteroidCollision(vector <int> &asteroids) {
		stack <int> s;
		for (auto x : asteroids) {
			while (s.size()) {
				if (x > 0) break;
				else {
                    if (x + s.top() == 0) break;
					else if (s.top() > 0 && s.top() + x < 0) s.pop();
					else break;
				}
			}
			if (s.empty()) s.push(x);
			else if (x < 0 && x + s.top() == 0) s.pop();
			else if (s.top() > 0 && x < 0 && s.top() + x > 0) {}
			else s.push(x);
		}

		vector <int> ans;
		while (s.size()) {
			ans.push_back(s.top());
			s.pop();
		}
        reverse(ans.begin(), ans.end());
		return ans;
	}
};