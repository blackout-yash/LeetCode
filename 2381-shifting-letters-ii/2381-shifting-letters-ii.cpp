class Solution {
public:
    string shiftingLetters(string s, vector<vector<int>>& shifts) {
        map <int, int> posStart, negStart, posEnd, negEnd;
        for(auto x: shifts) {
            int l = x[0], r = x[1];
            if(x[2]) {
                posStart[l]++;
                posEnd[r]--;
            } else {
                negStart[l]--;
                negEnd[r]++;
            }
        } 
        
        int n = s.size(), curr = 0;
        for(int i = 0; i < n; i++) {            
            curr += (posStart[i] + negStart[i]);
            int temp = (((s[i] - 'a' + curr) % 26) + 26) % 26;
            s[i] = (char) 'a' + temp;
            curr += (posEnd[i] + negEnd[i]);
        }
        return s;
    }
};