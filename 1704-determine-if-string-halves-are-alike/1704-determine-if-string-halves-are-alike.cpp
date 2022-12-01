class Solution {
public:
    bool halvesAreAlike(string s) {
        vector <char> temp = {'a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U'};
        map <char, int> m;
        for(auto x: temp) m[x] = 1;
        
        int cnt = 0, n = s.size();
        for(int i = 0; i < n; i++) {
            if(2 * i < n) cnt += m[s[i]];
            else cnt -= m[s[i]];
        }
        return !cnt;
    }
};