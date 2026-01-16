class Solution {
public:
    int maximizeSquareArea(int n, int m, vector <int> &hFences, vector <int> &vFences) {
        hFences.insert(hFences.begin(), 1);
        vFences.insert(vFences.begin(), 1);
        hFences.push_back(n);
        vFences.push_back(m);
        sort(begin(hFences), end(hFences));
        sort(begin(vFences), end(vFences));

        unordered_map <int, int> store;
        long long ans = -1, MOD = 1e9 + 7;
        for(int i = 0; i < hFences.size(); i++) {
            for(int j = 0; j < vFences.size(); j++) {
                int x = hFences[i],
                    y = vFences[j],
                    diff = x - y;
                if(store.count(diff)) {
                    int size = abs(x - store[diff]);
                    ans = max(ans, 1ll * size * size);
                } else store[diff] = x;
            }
        }
        return ans % MOD;
    }
};