class Solution {
public:
	void dfs(int root, int dest, vector <int> &path, vector<vector<int>> &ans, vector <int> &vis, vector<vector<int>> &graph) {
		path.push_back(root);
		if (root == dest) {
			ans.push_back(path);
			path.pop_back();
			return;
		}
		vis[root] = 1;

		for (int child : graph[root]) {
			if (vis[child]) continue;
			dfs(child, dest, path, ans, vis, graph);
		}

		vis[root] = 0;
		path.pop_back();
	}

	vector<vector<int>> allPathsSourceTarget(vector<vector<int>> &graph) {
		int n = graph.size();
		vector <vector<int>> ans;
		vector <int> path, vis(n);

		dfs(0, n - 1, path, ans, vis, graph);

		return ans;
	}
};