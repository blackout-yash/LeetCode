class Solution {
public:
    bool canCross(vector <int> &stones) {
        map <int, int> ind;
        int n = stones.size();
        for(int i = 0; i < n; i++) ind[stones[i]] = i;
        
        vector <set<int>> vis(n);
        queue <pair <int, int>> q;
        q.push({stones[0], 0}); 
        vis[0].insert(0);
        
        while(q.size()) {
            int root = q.front().first,
                val = q.front().second;
            q.pop();
            
            if(stones.back() == root) return true;
            
            for(int i = -1; i <= 1; i++) {
                int curr = val + i,
                    child = root + curr;
                if(ind.count(child)) {
                    int cnt = ind[child];
                    if(vis[cnt].find(curr) == vis[cnt].end()) {
                        q.push({child, curr});
                        vis[cnt].insert(curr);
                    }
                } 
            }
        }
        return false;
    }
};