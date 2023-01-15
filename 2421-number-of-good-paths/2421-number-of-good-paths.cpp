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

class Solution {
public:
    int numberOfGoodPaths(vector <int> &vals, vector<vector<int>> &edges) {
        int n = vals.size();

        vector <vector <int>> graph(n);
        for (auto x : edges) {
            int u = x[0], v = x[1];
            graph[u].push_back(v);
            graph[v].push_back(u);
        }

        vector <pair<int, int>> sorted;
        for (int i = 0; i < n; i++) sorted.push_back({vals[i], i});
        sort(sorted.begin(), sorted.end());

        DSU d(n);

        set <pair<int, int>> s;
        int ans = n, prev = -1;
        for (auto x : sorted) {
            int val = x.first,
                root = x.second;
            
            for (auto y : graph[root]) {
                if (vals[y] <= val) d.unionSets(root, y);
            }
            
            if (prev == val) {
                int cnt = 1;
                vector <pair<int, int>> temp;
                for (auto y : s) {
                    int u = y.first, v = y.second;
                    if (d.findSet(root) == d.findSet(u)) {
                        cnt += v;
                        ans += v;
                        temp.push_back(y);
                    }
                }
                for (auto x : temp) s.erase(x);
                s.insert({root, cnt});
            } else {
                prev = val;
                s.clear();
                s.insert({root, 1});
            }
        }
        return ans;
    }
};