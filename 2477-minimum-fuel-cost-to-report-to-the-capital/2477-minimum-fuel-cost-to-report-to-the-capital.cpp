#define ll long long
class Solution {
public:
	ll bfs(int root, int par, ll &ans, int seats, vector<vector<int>> &graph) {
		ll nodes = 1;
		for (int child : graph[root]) {
			if (child == par) continue;
			ll curr = bfs(child, root, ans, seats, graph);
			ans += ((curr / seats) + (curr % seats != 0));
			nodes += curr;
		}
		return nodes;
	}

	ll minimumFuelCost(vector<vector<int>> &roads, int seats) {
		int n = roads.size();
		vector <vector<int>> graph(n + 1);
		for (auto x : roads) {
			graph[x[0]].push_back(x[1]);
			graph[x[1]].push_back(x[0]);
		}

		ll ans = 0;
		bfs(0, -1, ans, seats, graph);
		return ans;
	}
};