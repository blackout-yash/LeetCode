class Solution {
public:
    int maxSatisfaction(vector<int>& satisfaction) {
        int ans = 0, sum = 0, n = satisfaction.size();
        sort(satisfaction.begin(), satisfaction.end());
        for(int i = n - 1; i >= 0; i--) {
            if(satisfaction[i] + sum >= 0) {
                ans += (satisfaction[i] + sum);
                sum += satisfaction[i];
            }
        }
        return ans;
    }
};