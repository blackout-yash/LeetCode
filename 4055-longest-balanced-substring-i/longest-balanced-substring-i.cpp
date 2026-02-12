class Solution {
public:
    bool isPossible(map <char, int> &m) {
        int mn = 1e9, mx = -1e9;
        for(auto x: m) {
            mn = min(mn, x.second);
            mx = max(mx, x.second);
        }
        return (mn == mx);
    }

    int longestBalanced(string s) {
        int n = s.size(), ans = 1; 
        for(int i = 0; i < n; i++) {
            map <char, int> m;
            for(int j = i; j < n; j++) {
                m[s[j]]++;
                if(isPossible(m)) ans = max(ans, j - i + 1);
            }
        }
        return ans;
    }
};