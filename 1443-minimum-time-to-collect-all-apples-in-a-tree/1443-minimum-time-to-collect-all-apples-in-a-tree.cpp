class Solution {
public:
	int dfs(int root, int par, bool &flag, vector<bool> &hasApple, vector<vector<int>> &graph) {
		int ans = 0;
		for (auto child : graph[root]) {
			if (child == par) continue;
            flag = false;
			int temp = dfs(child, root, flag, hasApple, graph);
			if (flag || temp) ans += (2 + temp);
		}
		if (hasApple[root]) flag = true;
		return ans;
	}

	int minTime(int n, vector<vector<int>> &edges, vector<bool> &hasApple) {
		vector <vector <int>> graph(n);
		for (auto x : edges) {
			int u = x[0], v = x[1];
			graph[u].push_back(v);
			graph[v].push_back(u);
		}
        
        bool flag;
		int ans = dfs(0, -1, flag, hasApple, graph);

		return ans;
	}
};