class Solution {
public:
    int level(int root, int curr, int par, int &alpha, vector <int> &store, vector<vector<int>> &graph) {
        int sum = curr, start = alpha;
        for(int child: graph[root]) {
            if(child != par) sum += level(child, curr + 1, root, alpha, store, graph);
        }
        store[root] = alpha - start;
        alpha++;
        return sum;
    }
    
    void dfs(int root, int par, int n, vector <int> &ans, vector <int> &store, vector<vector<int>> &graph) {
        for(int child: graph[root]) {
            if(child != par) {
                if(child) ans[child] = (ans[root] + n) - ((2 * store[child]) + 2);
                dfs(child, root, n, ans, store, graph);
            }
        }
    }
    
    vector <int> sumOfDistancesInTree(int n, vector<vector<int>> &edges) {
        vector <vector <int>> graph(n);
        for(auto x: edges) {
            int u = x[0],
                v = x[1];
            graph[u].push_back(v);
            graph[v].push_back(u);
        }
        
        int alpha = 0;
        vector <int> ans(n), store(n);
        int total = level(0, 0, -1, alpha, store, graph);
        
        ans[0] = total;
        dfs(0, -1, n, ans, store, graph);
        
        return ans;
    }
};