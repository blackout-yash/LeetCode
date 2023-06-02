class Solution {
public:
    int maximumDetonation(vector<vector<int>>& bombs) {
        int n = bombs.size(), ans = 1;
        for(int i = 0; i < n; i++) {
            int curr = 1;
            queue <int> q;
            vector <int> vis(n);
            q.push(i); vis[i] = 1;
            
            while(q.size()) {
                long ind = q.front(),
                    X = bombs[ind][0],
                    Y = bombs[ind][1],
                    rad = 1l * bombs[ind][2] * bombs[ind][2];
                q.pop();
                
                for(int j = 0; j < n; j++) {
                    if(vis[j]) continue;
                    long x = bombs[j][0],
                        y = bombs[j][1],
                        dist = ((x - X) * (x - X)) + ((y - Y) * (y - Y));
                    if(rad >= dist) {
                        curr++;
                        q.push(j);
                        vis[j] = 1;
                    }
                } ans = max(ans, curr);
            }    
        }
        return ans;
    }
};