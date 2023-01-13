class Solution {
public:
	int dfs(int root, int par, vector <int> &ans, string &s, vector <vector<int>> &graph) {
		int max1 = 0, max2 = 0;
		for (int child : graph[root]) {
			if (child == par) continue;
			int temp = dfs(child, root, ans, s, graph);
			if (s[root] != s[child]) {
				if (temp > max1) {
					max2 = max1;
					max1 = temp;
				} else max2 = max(max2, temp);
			}
		}
		ans[root] = 1 + max1 + max2;
		return 1 + max(max1, max2);
	}

	int longestPath(vector <int> &parent, string s) {
		int n = parent.size();
		vector <vector<int>> graph(n);
		for (int i = 1; i < n; i++) {
			int u = i, v = parent[i];
			graph[u].push_back(v);
			graph[v].push_back(u);
		}

		vector <int> ans(n, 1);
		dfs(0, -1, ans, s, graph);

		return *max_element(ans.begin(), ans.end());
	}
};