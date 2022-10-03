class Solution {
public:
    int minCost(string colors, vector<int>& neededTime) {
        int ans = 0, n = colors.size();
        for(int i = 0; i < n; i++){
            int j = i, sum = 0, _max = 0;
            while(true){
                if(j == n) break;
                else if(colors[i] != colors[j]) break;
                sum += neededTime[j];
                _max = max(_max, neededTime[j]);
                j++;
            }
            ans += (sum - _max);
            i = j - 1;
        }
        return ans;
    }
};