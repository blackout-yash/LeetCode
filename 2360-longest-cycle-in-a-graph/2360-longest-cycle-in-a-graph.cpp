class Solution {
public:
    void dfs(int root, int curr, int &ans, vector <int> &vis, vector <int> &size, vector <int> &edge) {
        vis[root] = 1;
        size[root] = curr;
        
        int child = edge[root];
        if(child == -1) {}
        else if(size[child]) ans = max(ans, curr - size[child] + 1);
        else if(!vis[child])dfs(child, curr + 1, ans, vis, size, edge);
        
        size[root] = 0;
    }
    
    int longestCycle(vector <int> &edges) {
        int n = edges.size(), ans = -1;
        vector <int> vis(n), size(n);
        for(int i = 0; i < n; i++) {
            if(!vis[i]) dfs(i, 1, ans, vis, size, edges);
        }
        return ans;
    }
};