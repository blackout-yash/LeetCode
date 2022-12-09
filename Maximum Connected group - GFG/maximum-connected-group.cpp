//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class DSU {
public:
	vector <int> parent, _size;

	DSU (int n) {
		parent.resize(n);
		_size.resize(n);
		for (int i = 0; i < n; i++) {
			parent[i] = i;
			_size[i] = 1;
		}
	}

	int findSet(int v) {
		if (v == parent[v]) return v;
		return parent[v] = findSet(parent[v]);
	}

	void unionSets(int a, int b) {
		a = findSet(a);
		b = findSet(b);
		if (a != b) {
			if (_size[a] < _size[b]) swap(a, b);
			parent[b] = a;
			_size[a] += _size[b];
		}
	}
};

vector <vector <int>> movements = {{1, 0}, { -1, 0}, {0, 1}, {0, -1}};

int index(int i, int j, int n) {
	return (i * n) + j;
}

bool isValid(int i, int j, int n) {
	return i >= 0 && i < n && j >= 0 && j < n;
}

class Solution {
public:
	int MaxConnection(vector <vector <int>> &grid) {
		int n = grid.size();
		DSU d(n * n);

		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (grid[i][j]) {
					for (auto move : movements) {
						int x = i + move[0],
						    y = j + move[1];
						if (isValid(x, y, n) && grid[x][y]) {
							int ind1 = index(i, j, n),
							    ind2 = index(x, y, n);
							d.unionSets(ind1, ind2);
						}
					}
				}
			}
		}

		int ans = 0;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (grid[i][j]) {
					int ind = index(i, j, n),
					    par = d.findSet(ind);
					ans = max(ans, d._size[par]);
				} else {
					set <int> s;
					for (auto move : movements) {
						int x = i + move[0],
						    y = j + move[1];
						if (isValid(x, y, n) && grid[x][y]) {
							int ind = index(x, y, n),
							    par = d.findSet(ind);
							s.insert(par);
						}
					}

					int temp = 1;
					for (auto x : s) temp += d._size[x];

					ans = max(ans, temp);
				}
			}
		}
		return ans;
	}
};


//{ Driver Code Starts.
int main() {

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int>> grid(n, vector<int>(n));

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> grid[i][j];
            }
        }

        Solution obj;
        cout<<obj.MaxConnection(grid)<<"\n";
    }
}

// } Driver Code Ends