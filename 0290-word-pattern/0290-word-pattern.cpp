class Solution {
public:
    bool wordPattern(string pattern, string s) {
        string temp;
        map <char, string> m1;
        map <string, char> m2;
        int n = s.size(), j = 0;
        for(int i = 0; i < n; i++) {
            if(s[i] != ' ') temp.push_back(s[i]);
            
            if(s[i] == ' ' || i + 1 == n) {
                if(m1.count(pattern[j]) && m1[pattern[j]] != temp) return false;
                else if(m2.count(temp) && m2[temp] != pattern[j]) return false;
                m1[pattern[j]] = temp;
                m2[temp] = pattern[j];
                temp.clear(); j++;
            }
        }
        return (j == pattern.size());
    }
};