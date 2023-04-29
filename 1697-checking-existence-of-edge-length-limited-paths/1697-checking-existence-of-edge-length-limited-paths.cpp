class DSU {
public:
	vector <int> parent, _size;
	
	DSU (int n) {
		parent.resize(n);
		_size.resize(n);
		for(int i = 0; i < n; i++) {
			parent[i] = i;
			_size[i] = 1;
		}
	}

	void makeSet(int v) {
		parent[v] = v;
		_size[v] = 1;
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

bool comp(const vector<int> &v1, const vector<int> &v2){
    return v1[2] < v2[2];
}

class Solution {    
public:
    vector<bool> distanceLimitedPathsExist(int edge, vector<vector<int>> &edgeList, vector<vector<int>> &queries) {
        sort(edgeList.begin(), edgeList.end(), comp);
        
        set <pair <int, int>> s;
        int n = edgeList.size(), m = queries.size();
        for(int i = 0; i < m; i++) s.insert({queries[i][2], i});
        
        
        DSU d = DSU(edge);
        
        int i = 0;
        vector <bool> ans(m);
        for(auto x: s) {
            int range = x.first,
                ind = x.second;
            while(i < n) {
                if(range <= edgeList[i][2]) break;
                d.unionSets(edgeList[i][0], edgeList[i][1]);
                i++;
            }
            if(d.findSet(queries[ind][0]) == d.findSet(queries[ind][1])) ans[ind] = true;
        }
        return ans;
    }
};