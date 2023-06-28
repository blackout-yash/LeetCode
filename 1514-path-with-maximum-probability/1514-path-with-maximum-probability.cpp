class Solution {
public:
    
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start, int end) {
        vector<pair<int,double>>v[n];
        vector<int> visited(n);
        vector<double> ans(n);

        for(int i = 0; i < edges.size(); i++){
            v[edges[i][0]].push_back({edges[i][1], succProb[i]});
            v[edges[i][1]].push_back({edges[i][0], succProb[i]});
        }

        priority_queue<pair<double,int>> pq;
        pq.push({1, start});
        
        while(pq.size()) {
            pair<double,int> z = pq.top();
            pq.pop();
            ans[z.second] = max(ans[z.second], z.first);
            
            if(visited[z.second]) continue;

            visited[z.second]=1;
            for(int i = 0; i < v[z.second].size(); i++) {
                pq.push({z.first * v[z.second][i].second, v[z.second][i].first});
            }
        }

        return ans[end];
    }
};