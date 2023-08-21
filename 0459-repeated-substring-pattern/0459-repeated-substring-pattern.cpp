class Solution {
public:
    bool repeatedSubstringPattern(string s) {
        int n = s.size();
        for(int i = 0; i < n / 2; i++) {
            if(n % (i + 1)) continue;
            bool flag = true;
            for(int j = 0; j < n; j++) {
                if(s[j % (i + 1)] != s[j]) {
                    flag = false;
                    break;
                }
            }
            if(flag) return flag;
        }
        return false;
    }
};