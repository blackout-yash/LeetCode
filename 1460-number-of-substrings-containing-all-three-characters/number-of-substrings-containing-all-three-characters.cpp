class Solution {
public:
    int numberOfSubstrings(string s) {
        map <char, int> m;
        int n = s.size(), i = 0, j = 0, ans = 0;
        while(j < n) {
            m[s[j]]++;
            while(m.size() == 3) {
                ans += (n - j);
                if(m[s[i]] == 1) m.erase(s[i]);
                else m[s[i]]--;
                i++;
            }
            j++;
        }
        return ans;
    }
};