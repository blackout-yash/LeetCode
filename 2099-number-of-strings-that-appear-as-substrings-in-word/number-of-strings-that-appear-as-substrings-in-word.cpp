class Solution {
public:
    int numOfStrings(vector <string> &patterns, string word) {
        int n = word.size(), ans = 0;
        for(auto x: patterns) {
            int m = x.size(), cnt = 1;
            for(int i = 0; i <= n - m; i++) {
                int flg = true;
                for(int j = i; j < i + m; j++) {
                    if(x[j - i] != word[j]) {
                        flg = false;
                        break;
                    }
                }
                if(flg) {
                    ans++;
                    break;
                }
            }
        }
        return ans;
    }
};