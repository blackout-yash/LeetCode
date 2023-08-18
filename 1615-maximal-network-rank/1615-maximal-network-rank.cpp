class Solution {
public:   
    int maximalNetworkRank(int n, vector<vector<int>>& roads) {
        vector <int> graph(n);
        set <pair <int, int>> s;
        for(auto x: roads) {
            graph[x[0]]++;
            graph[x[1]]++;
            s.insert({x[0], x[1]});
            s.insert({x[1], x[0]});
        }
                
        int ans = 0;
        for(int i = 0; i < n; i++) {
            for(int j = i + 1; j < n; j++) {
                int curr = graph[i] + graph[j] - (s.find({i, j}) != s.end());
                ans = max(ans, curr);
            }
        }
        return ans;
    }
};