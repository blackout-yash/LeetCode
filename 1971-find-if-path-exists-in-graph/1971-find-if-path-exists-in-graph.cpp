class Solution {
public:
	bool dfs(int root, int dest, vector <int> &vis, vector <vector <int>> &graph) {
		if (root == dest) return true;
		vis[root] = 1;
		for (int child : graph[root]) {
			if (vis[child]) continue;
			else if (dfs(child, dest, vis, graph)) return true;
		}
		return false;
	}

	bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
		vector <vector <int>> graph(n + 1);
		for (auto x : edges) {
			int u = x[0],
			    v = x[1];
			graph[u].push_back(v);
			graph[v].push_back(u);
		}

		vector <int> vis(n + 1);

		return dfs(source, destination, vis, graph);
	}
};