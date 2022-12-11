//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++
class Solution {
public:
	int timer = 1;
	void dfs(int root, int par, vector <int> &mark, vector <int> &time, vector <int> &low, vector <int> &vis, vector<int> adj[]) {
		vis[root] = 1;
		time[root] = low[root] = timer;
		timer += 1;
		int unVistedChild = 0;
		for (int child : adj[root]) {
			if (child == par) continue;
			else if (vis[child]) {
				low[root] = min(low[root], time[child]);
				continue;
			}
			dfs(child, root, mark, time, low, vis, adj);
			low[root] = min(low[root], low[child]);
			if (low[child] >= time[root] && par != -1) {
				mark[root] = 1;
			}
			unVistedChild++;
		}

		if (unVistedChild > 1 && par == -1) {
			mark[root] = 1;
		}
	}

	vector <int> articulationPoints(int V, vector<int> adj[]) {
		vector <int> vis(V), mark(V), time(V), low(V);
		for (int i = 0; i < V; i++) {
			if (vis[i]) continue;
			dfs(i, -1, mark, time, low, vis, adj);
		}

		vector <int> ans;
		for (int i = 0; i < V; i++) {
			if (mark[i]) ans.push_back(i);
		}

		if (ans.empty()) return { -1};
		return ans;
	}
};


//{ Driver Code Starts.

int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int V, E;
		cin >> V >> E;
		vector<int>adj[V];
		for(int i = 0; i < E; i++){
			int u, v;
			cin >> u >> v;
			adj[u].push_back(v);
			adj[v].push_back(u);
		}
		Solution obj;
		vector<int> ans = obj.articulationPoints(V, adj);
		for(auto i: ans)cout << i << " ";
		cout << "\n";
	}
	return 0;
}
// } Driver Code Ends