class Solution {
public:
    bool isPossibleUtil(map <int, set <int>> &m, vector <int> &alpha, vector <int> &comb) {
        vector <int> node(4);
        for(int i = 0; i < 4; i++) node[i] = alpha[comb[i] - 1];
        if(m[node[0]].find(node[1]) != m[node[0]].end()) return false;
        if(m[node[2]].find(node[3]) != m[node[2]].end()) return false;
        return true;
    }
    
    bool isPossible(int n, vector<vector<int>>& edges) {
        map <int, int> deg;
        map <int, set <int>> edge;
        for(auto x: edges) {
            int u = x[0],
                v = x[1];
            deg[u]++; deg[v]++;
            edge[u].insert(v);
            edge[v].insert(u);
        }
        
        int cnt = 0;
        vector <int> alpha;
        for(auto x: deg) {
            if(x.second & 1) {
                cnt++;
                alpha.push_back(x.first);
            }
        }
        
        if(!cnt) return true;
        else if(cnt & 1) return false;
        else if(cnt > 4) return false;
        else if(cnt == 2) {
            if(edge[alpha[0]].find(alpha[1]) != edge[alpha[0]].end()) {
                if(edge[alpha[0]] == edge[alpha[1]]) {
                    if(edge[alpha[0]].size() >= n - 2) return false;
                    return true;
                } else if(edge[alpha[0]].size() == n - 1 || edge[alpha[1]].size() == n - 1) return false;
                else return true;
            } return true;
        }
        
        vector <int> comb1 = {1, 2, 3, 4},
                     comb2 = {1, 3, 2, 4},
                     comb3 = {1, 4, 2, 3};
        
        if(isPossibleUtil(edge, alpha, comb1)) return true;
        else if(isPossibleUtil(edge, alpha, comb2)) return true;
        else if(isPossibleUtil(edge, alpha, comb3)) return true;
        return false;
    }
};