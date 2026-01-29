class Solution {
public:
    long long minimumCost(string source, string target, vector <char> &original, vector <char> &changed, vector <int> &cost) {
        int m = original.size();
        vector <vector <long long>> arr(26, vector <long long> (26, 1e12));
        for(int i = 0; i < m; i++) {
            int x = original[i] - 'a',
                y = changed[i] - 'a';
            arr[x][y] = min(arr[x][y], 1ll * cost[i]);
        }

        for(int i = 0; i < 26; i++) {
            for(int j = 0; j < 26; j++) {
                for(int k = 0; k < 26; k++) arr[j][k] = min(arr[j][k], arr[j][i] + arr[i][k]);
            }
        }

        long long n = source.size(), ans = 0;
        for(int i = 0; i < n; i++) {
            int x = source[i] - 'a',
                y = target[i] - 'a';
            if(x == y) continue;
            if(arr[x][y] >= 1e12) return -1;
            ans += arr[x][y];
        }
        return ans;
    }
};