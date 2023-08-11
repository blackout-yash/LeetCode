class Solution {
public:
    string shiftingLetters(string s, vector<vector<int>>& shifts) {
        map <int, int> start, end;
        for(auto x: shifts) {
            int l = x[0], r = x[1];
            if(x[2]) {
                start[l]++;
                end[r]--;
            } else {
                start[l]--;
                end[r]++;
            }
        } 
        
        int n = s.size(), curr = 0;
        for(int i = 0; i < n; i++) {            
            curr += start[i];
            int temp = (((s[i] - 'a' + curr) % 26) + 26) % 26;
            s[i] = (char) 'a' + temp;
            curr += end[i];
        }
        return s;
    }
};