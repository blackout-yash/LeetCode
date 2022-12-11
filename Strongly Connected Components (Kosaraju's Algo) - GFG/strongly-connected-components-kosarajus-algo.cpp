//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends


class Solution {
public:
	void dfs(int root, stack <int> &time, vector <int> &vis, vector<int> adj[]) {
		vis[root] = 1;
		for (int child : adj[root]) {
			if (vis[child]) continue;
			dfs(child, time, vis, adj);
		}
		time.push(root);
	}

	void dfsScc(int root, vector <int> &path, vector <int> &vis, vector<int> adjT[]) {
		vis[root] = 1;
		path.push_back(root);
		for (int child : adjT[root]) {
			if (vis[child]) continue;
			dfsScc(child, path, vis, adjT);
		}
	}

	int kosaraju(int V, vector<int> adj[]) {
		stack <int> time;
		vector <int> vis(V);
		for (int i = 0; i < V; i++) {
			if (vis[i]) continue;
			dfs(i, time, vis, adj);
		}

		vector <int> adjT[V];
		for (int i = 0; i < V; i++) {
			vis[i] = 0;
			for (int child : adj[i]) {
				adjT[child].push_back(i);
			}
		}

		int sccCnt = 0;
		vector <vector<int>> scc;
		while(!time.empty()) {
		    int node = time.top();
		    time.pop();
			if (vis[node]) continue;
			sccCnt++;
			vector <int> path;
			dfsScc(node, path, vis, adjT);
			scc.push_back(path);
		}

		return sccCnt;
	}
};

//{ Driver Code Starts.


int main()
{
    
    int t;
    cin >> t;
    while(t--)
    {
    	int V, E;
    	cin >> V >> E;

    	vector<int> adj[V];

    	for(int i = 0; i < E; i++)
    	{
    		int u, v;
    		cin >> u >> v;
    		adj[u].push_back(v);
    	}

    	Solution obj;
    	cout << obj.kosaraju(V, adj) << "\n";
    }

    return 0;
}


// } Driver Code Ends