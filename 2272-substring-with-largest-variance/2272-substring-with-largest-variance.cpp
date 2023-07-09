class Solution {
public:
    int largestVar(string &s) {
        int ans = 0;
        for(char i = 'a'; i <= 'z'; i++) {
            for(char j = 'a'; j <= 'z'; j++) {
                int cnt1 = 0, cnt2 = 0;
                for(auto x: s) {
                    cnt1 += (x == i);
                    cnt2 += (x == j);
                    if(cnt1 < cnt2) cnt1 = cnt2 = 0;
                    if(cnt1 && cnt2) ans = max(ans, cnt1 - cnt2);
                }
            }
        }
        return ans;
    }
    
    int largestVariance(string s) {
        int ans1 = largestVar(s);
        reverse(begin(s), end(s));
        int ans2 = largestVar(s);
        
        return max(ans1, ans2);
    }
};