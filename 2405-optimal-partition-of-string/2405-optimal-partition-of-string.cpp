class Solution {
public:
    int partitionString(string s) {
        map <char, bool> m;
        int ans = 1, n = s.size();
        for(int i = 0; i < n; i++) {
            if(m.count(s[i])) {
                ans++; m.clear();
            }  
            m[s[i]] = true;
        }
        return ans;
    }
};