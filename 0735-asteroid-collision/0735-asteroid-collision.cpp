class Solution {
public:
	vector<int> asteroidCollision(vector <int> &asteroids) {
		stack <int> s;
		int n = asteroids.size();
		for (int i = n - 1; i >= 0; i--) {
            int x = asteroids[i];
			while (s.size()) {
				if (x < 0) break;
				else {
					if (x + s.top() == 0) break;
					else if (s.top() < 0 && s.top() + x > 0) s.pop();
					else break;
				}
			}

			if (s.empty()) s.push(x);
			else if (x > 0 && x + s.top() == 0) s.pop();
			else if (s.top() < 0 && x > 0 && s.top() + x < 0) {}
			else s.push(x);
		}

		vector <int> ans;
		while (s.size()) {
			ans.push_back(s.top());
			s.pop();
		}
		return ans;
	}
};