#define f first
#define s second
class Solution {
public:
	vector <vector<int>> insert(int n, vector <vector<int>> &edges) {
		vector <vector<int>> graph(n);
		for (auto x : edges) {
			int u = x[0], v = x[1];
			graph[u].push_back(v);
		}
		return graph;
	}

	void insert(int node, int color, queue <pair<int, int>> &q, vector <vector<int>> &vis, vector <vector<int>> &graph) {
		for (auto child : graph[node]) {
			if (vis[child][!color] > vis[node][color] + 1) {
				q.push({child, !color});
				vis[child][!color] = vis[node][color] + 1;
			}
		}
	}

	vector<int> shortestAlternatingPaths(int n, vector<vector<int>> &redEdges, vector<vector<int>> &blueEdges) {
		vector <vector<int>> graph0 = insert(n, redEdges),
		                     graph1 = insert(n, blueEdges);
		queue <pair<int, int>> q;
		vector <vector<int>> vis(n, vector<int> (2, 1e9));
		q.push({0, 0});
		q.push({0, 1});
		vis[0][0] = vis[0][1] = 0;

		while (!q.empty()) {
			int node = q.front().f,
			    color = q.front().s;
			q.pop();

			if (!color) insert(node, color, q, vis, graph1);
			else insert(node, color, q, vis, graph0);
		}

		vector <int> ans;
		for (auto x : vis) {
			int _min = min(x[0], x[1]);
			if (_min >= 1e9) ans.push_back(-1);
			else ans.push_back(_min);
		}

		return ans;
	}
};