class Solution {
public:
    int minFlipsMonoIncr(string s) {
        int one = 0, zero = 0;
        for(auto x: s) {
            if(x == '1') one++;
        }
        
        int n = s.size(), ans = n;
        for(int i = n; i >= -1; i--) {
            ans = min(ans, one + zero);
            if(0 <= i && i < n) { 
                if(s[i] == '1') one--;
                else zero++;
            }
        } 
        return ans;
    }
};