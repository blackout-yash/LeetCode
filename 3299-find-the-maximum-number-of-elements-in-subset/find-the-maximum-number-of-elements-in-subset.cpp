class Solution {
public:
    int maximumLength(vector <int> &nums) {
        map <int, int> m;
        for(auto x: nums) m[x]++;

        int ans = 0;
        for(auto x: m) {
            long long curr = x.first, cnt = 0;
            while(true) {
                if(!m.count(curr)) break;
                else if(curr == 1) {
                    cnt = m[curr];
                    break;
                } else if(m[curr] == 1) {
                    cnt++;
                    break;
                } else {
                    cnt += 2;
                    if(curr >= 1e9) break;
                    curr *= curr;
                }
            }
            if(cnt % 2 == 0) cnt--;
            ans = max(1ll*ans, cnt);
        }

        return ans;
    }
};