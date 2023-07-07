class Solution {
public:
    int maxConsecutiveAnswers(string s, int k) {
        int one = 0, two = 0, j1 = 0, j2 = 0, ans = 0, n = s.size();
        for(int i = 0; i < n; i++) {
            one += (s[i] == 'F');
            two += (s[i] == 'T');
            
            while(one > k) one -= (s[j1++] == 'F');
            while(two > k) two -= (s[j2++] == 'T');
            ans = max(ans, i - min(j1, j2) + 1);
        }
        return ans;
    }
};