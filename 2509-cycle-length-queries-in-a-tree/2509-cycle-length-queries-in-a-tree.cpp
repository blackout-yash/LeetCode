class Solution {
public:
    vector<int> cycleLengthQueries(int n, vector<vector<int>> &queries) {
        vector <int> store;
        for(auto x: queries) {
            int node1 = x[0], node2 = x[1],
                cnt = 1, ans = 0;
            map <int, int> m;
            while(true) {
                if(!node1) break;
                m[node1] = cnt;
                node1 /= 2;
                cnt++;
            }
            while(true) {
                if(m.count(node2)) {
                    ans += m[node2];
                    break;
                } 
                ans++;
                node2 /= 2;
            }
            store.push_back(ans);
        }
        return store;
    }
};