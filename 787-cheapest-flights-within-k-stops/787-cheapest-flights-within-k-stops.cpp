class Solution {
public:
	int findCheapestPrice(int n, vector<vector<int>> &flights, int src, int dst, int k) {
		vector <vector<pair<int, int>>> graph(n);
		for (auto x : flights) graph[x[0]].push_back({x[1], x[2]});

        k++;
		vector <vector<int>> vis(k + 1, vector<int> (n, 1e9));
		vis[k][src] = 0;

		priority_queue <pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;
		pq.push({0, {k, src}});

		while (!pq.empty()) {
			int dis = pq.top().first,
			    left = pq.top().second.first,
			    node = pq.top().second.second;
            pq.pop();
            
			if (left) {
				for (auto it : graph[node]) {
					int currNode = it.first,
					    currDis = it.second;
                    
					if (vis[left - 1][currNode] > dis + currDis) {
						vis[left - 1][currNode] = dis + currDis;
						pq.push({vis[left - 1][currNode], {left - 1, currNode}});
					}
				}
			}
		}

		int ans = 1e9;
		for (int i = 0; i <= k; i++) ans = min(ans, vis[i][dst]);

		if (ans == 1e9) return -1;
		return ans;
	}
};