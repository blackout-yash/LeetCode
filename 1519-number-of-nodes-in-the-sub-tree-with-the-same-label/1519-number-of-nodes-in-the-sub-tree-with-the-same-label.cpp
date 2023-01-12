class Solution {
public:
	void dfs(int root, int par, vector <vector<int>> &ans, string &labels, vector <vector<int>> &graph) {
		for (int child : graph[root]) {
			if (child == par) continue;
			dfs(child, root, ans, labels, graph);
			for (int i = 0; i < 26; i++) ans[root][i] += ans[child][i];
		} ans[root][labels[root] - 'a']++;
	}

	vector<int> countSubTrees(int n, vector<vector<int>> &edges, string labels) {
		vector <vector<int>> graph(n), ans(n, vector <int> (26));
		for (auto x : edges) {
			int u = x[0], v = x[1];
			graph[u].push_back(v);
			graph[v].push_back(u);
		}

		dfs(0, -1, ans, labels, graph);

		vector <int> path(n);
		for (int i = 0; i < n; i++) path[i] = ans[i][labels[i] - 'a'];
		return path;
	}
};