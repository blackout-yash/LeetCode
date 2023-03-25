class Solution {
public:
    int dfs(int root, vector <int> &vis, vector <vector <int>> &graph){
        int ans = 1;
        vis[root] = 1;
        for(auto x: graph[root]) {
            if(vis[x]) continue;
            ans += dfs(x, vis, graph);
        }
        return ans;
    }
    
    long long countPairs(int n, vector<vector<int>>& edges) {
        vector <int> vis(n), temp;
        vector <vector<int>> graph(n);
        for(auto x: edges) {
            graph[x[0]].push_back(x[1]);
            graph[x[1]].push_back(x[0]);
        }
        
        for(int i = 0; i < n; i++) {
            if(vis[i]) continue;
            temp.push_back(dfs(i, vis, graph));
        }
        
        long long ans = 0; n = temp.size();
        for(int i = n - 2; i >= 0; i--) {
            ans += (1ll * temp[i] * temp[i + 1]);
            temp[i] += temp[i + 1];
        }
        
        return ans;
    }
};