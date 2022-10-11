//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution {
public:
	int spanningTree(int V, vector<vector<int>> adj[]) {
		priority_queue <pair <int, pair<int, int>>,
		               vector <pair <int, pair<int, int>>>,
		               greater <pair <int, pair<int, int>>>> pq;
		pq.push({0, {0, -1}});
		vector <int> vis(V);

		int mst = 0;
		vector <pair<int, int>> path;
		while (!pq.empty()) {
			int wt = pq.top().first,
			    node = pq.top().second.first,
			    par = pq.top().second.second;
			pq.pop();

			if (vis[node]) continue;

			vis[node] = 1;
			mst += wt;
			path.push_back({node, par});
			for (auto it : adj[node]) {
				int curr = it[0],
				    currWt = it[1];
				if (!vis[curr]) {
					pq.push({currWt, {curr, node}});
				}
			}
		}

		// For printing the tree
		// 	for (auto x : path) {
		// 		cout << "Node: " << x.first << " Parent: " << x.second << endl;
		// 	}
		return mst;
	}
};


//{ Driver Code Starts.


int main()
{
    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;
        vector<vector<int>> adj[V];
        int i=0;
        while (i++<E) {
            int u, v, w;
            cin >> u >> v >> w;
            vector<int> t1,t2;
            t1.push_back(v);
            t1.push_back(w);
            adj[u].push_back(t1);
            t2.push_back(u);
            t2.push_back(w);
            adj[v].push_back(t2);
        }
        
        Solution obj;
    	cout << obj.spanningTree(V, adj) << "\n";
    }

    return 0;
}


// } Driver Code Ends