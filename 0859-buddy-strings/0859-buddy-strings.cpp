class Solution {
public:
    bool buddyStrings(string s, string goal) {
        if(s.size() != goal.size()) return false;
        
        map <char, char> m;
        vector <int> freq(26);
        int n = s.size(), flag = 0, cnt = 0;
        for(int i = 0; i < n; i++) {
            if(s[i] != goal[i]) {
                if(m.size()) {
                    if(m[s[i]] != goal[i]) return false;
                    else cnt--;
                } else {
                    m[goal[i]] = s[i];
                    cnt++; flag = 1;
                }
            } else {
                int ind = s[i] - 'a';
                freq[ind]++;
                if(freq[ind] >= 2) flag = 1;
            }
        }
        if(cnt) return false;
        return flag;
    }
};