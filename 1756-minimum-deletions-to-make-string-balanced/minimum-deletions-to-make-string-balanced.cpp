class Solution {
public:
    int minimumDeletions(string s) {
        int b = 0;
        for(auto x: s) b += (x == 'b');

        int n = s.size(), a = 0, ans = b;
        for(int i = n - 1; i >= 0; i--) {
            if(s[i] == 'b') b--;
            else a++;
            ans = min(ans, a + b);
        }
        return ans;
    }
};