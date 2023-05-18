class Solution {
public:
     void dfs(int i, vector <int> &v, vector <int> ad[]){
        v[i] = 1;
        for(auto x : ad[i]){
            if(!v[x]) dfs(x, v, ad);
        }
    }
    
    void topo(int i, stack <int> &s, vector <int> &vis, vector <int> ad[]){
        vis[i] = 1;
        for(auto x : ad[i]){
            if(!vis[x]) topo(x, s, vis, ad);
        }
        s.push(i);
    }
    
    vector <int> findSmallestSetOfVertices(int n, vector <vector<int>> &edges) {
        stack <int> s;
        vector <int> ad[n];
        for(auto i : edges){
            ad[i[0]].push_back(i[1]);
        }
        
        vector <int> vis(n), a, v(n);
        for(int i = 0; i < n; i++){
            if(!vis[i]) topo(i, s, vis, ad);
        }
        
        while(s.size()){
            int x = s.top();
            s.pop();
            if(!v[x]){
                a.push_back(x);
                dfs(x, v, ad);
            }
        }
        
        return a;
    }
};