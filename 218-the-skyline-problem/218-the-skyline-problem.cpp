class Solution {
public:
    vector <int> push(int n, int m){
        vector <int> ans = {n, m};
        return ans;
    }
    
    vector<vector<int>> getSkyline(vector<vector<int>> &buildings) {
        vector <pair <int, int>> temp;
        for(auto x: buildings) {
            temp.push_back({x[0], -x[2]});
            temp.push_back({x[1], x[2]});            
        } sort(temp.begin(), temp.end());

        map <int, set <int>> m;
        priority_queue <int> q;
        
        int prev = -1;
        vector <vector <int>> ans;
        for(auto x: temp){
            int y = x.first, ht = x.second;
            if(ht < 0) q.push(-ht);
            else m[ht].insert(y);
            
            while(!q.empty()){
                int curr = q.top();
                if(m[curr].size()) {
                    m[curr].erase(m[curr].begin());
                    q.pop();
                } else break;
            }
            
            if(q.empty()) {
                if(prev) {
                    prev = 0;
                    ans.push_back(push(y, prev));
                }
            } else if(q.top() != prev) {
                prev = q.top();
                ans.push_back(push(y, prev));
            }
        }
        
        return ans;
    }
};