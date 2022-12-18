class Solution {
public:
    vector<int> cycleLengthQueries(int n, vector<vector<int>> &queries) {
        vector <int> store;
        for(auto x: queries) {
            int node1 = x[0], node2 = x[1],
                cnt = 1, ans = 0;
            while(true) {
                int level1 = log2(node1) + 1,
                    level2 = log2(node2) + 1;
                if(node1 == node2) {
                    ans++;
                    break;
                } else if(level1 == level2) {
                    node1 /= 2; node2 /= 2;
                    ans += 2;
                } else if(level1 > level2) {
                    node1 /= 2; ans++;
                } else {
                    node2 /= 2; ans++;
                }
            }
            store.push_back(ans);
        }
        return store;
    }
};