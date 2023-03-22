class Solution {
public:
    int minScore(int n, vector<vector<int>> &roads) {
        vector <vector <pair <int, int>>> graph(n + 1);
        for(auto x: roads) {
            graph[x[0]].push_back({x[1], x[2]});
            graph[x[1]].push_back({x[0], x[2]});
        }
        
        int ans = 1e9;
        queue <int> q;
        vector <int> vis(n + 1, 0);
        q.push(1); vis[1] = 1;
        while(!q.empty()) {
            int curr = q.front();
            q.pop();    
            
            for(auto x: graph[curr]) {
                int child = x.first,
                    wt = x.second;
                ans = min(ans, wt);
                if(!vis[child]) {
                    vis[child] = wt;
                    q.push(child);
                }
            }
        }
        return ans;
    }
};