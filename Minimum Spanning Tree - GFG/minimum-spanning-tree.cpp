//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class DSU {
public:
	vector <int> parent, _size;

	DSU (int n) {
		parent.resize(n);
		_size.resize(n);
	}

	void makeSet(int v) {
		parent[v] = v;
		_size[v] = 1;
	}

	int findSet(int v) {
		if (v == parent[v]) return v;
		return parent[v] = findSet(parent[v]);
	}

	void unionSet(int a, int b) {
		a = findSet(a);
		b = findSet(b);
		if (a != b) {
			if (_size[a] < _size[b]) swap(a, b);
			parent[b] = a;
			_size[a] += _size[b];
		}
	}
};

class Solution
{
	public:
	//Function to find sum of weights of edges of the Minimum Spanning Tree.
    int spanningTree(int V, vector<vector<int>> adj[]){
        vector <pair <int, pair <int, int>>> edge;
        for(int node = 0; node < V; node++) {
            for(auto it: adj[node]) {
                int u = node, v = it[0], wt = it[1];
                edge.push_back({wt, {u, v}});
            }
        } sort(edge.begin(), edge.end());
        
        DSU d = DSU(V);
        for(int node = 0; node < V; node++) d.makeSet(node);
        
        int mst = 0;
        for(auto it: edge) {
            int u = it.second.first, 
                v = it.second.second, 
                wt = it.first;
            if(d.findSet(u) != d.findSet(v)) {
                mst += wt;
                d.unionSet(u, v);
            }
        }
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