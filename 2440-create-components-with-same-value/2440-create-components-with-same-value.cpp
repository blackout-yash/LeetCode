class Solution {
public:
	vector <int> factors(int n) {
		vector <int> factor;
		for (int i = 1; i * i <= n; i++) {
			if (n % i == 0) {
				if (n / i != i) factor.push_back(n / i);
				factor.push_back(i);
			}
		} 
        sort(factor.begin(), factor.end()); 
        return factor;
	}

	int dfs(int root, int par, int tar, int &ans, vector <int> &val, vector <vector<int>> &graph) {
		int curr = val[root];
		for (int child : graph[root]) {
			if (child == par) continue;
			curr += dfs(child, root, tar, ans, val, graph);
		}
        
		if (ans != -1 && curr == tar) {
			ans++;
			return 0;
		} else if (curr > tar) ans = -1;
		return curr;
	}

	int componentValue(vector<int> &nums, vector<vector<int>>& edges) {
		int n = nums.size();
		vector <vector<int>> graph(n);
		for (auto x : edges) {
			graph[x[0]].push_back(x[1]);
			graph[x[1]].push_back(x[0]);
		}

		int sum = 0, _max = *max_element(nums.begin(), nums.end());
		for (auto x : nums) sum += x;

		vector <int> factor = factors(sum);

		for (auto x : factor) {
			if (_max > x) continue;
			else {
				int ans = 0;
				dfs(0, -1, x, ans, nums, graph);
                if(ans > 0) return ans - 1;
			}
		}

		return 0;
	}
};