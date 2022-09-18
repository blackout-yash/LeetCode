class Solution {
public:
    int trap(vector<int> &height) {
        
        int n = height.size(), j = 0, sum = 0, ans = 0;
        for(int i = 0; i < n; i++){
            sum += height[i];
            if(i == j) continue;
            else {
                if(height[i] >= height[j]) {
                    sum -= (height[i] + height[j]);
                    ans += ((height[j] * (i - j - 1)) - sum);
                    sum = height[i]; j = i;
                }
            }
        }
        
        int k = n - 1; sum = 0;
        for(int i = n - 1; i >= j; i--){
            sum += height[i];
            if(i == k) continue;
            else {
                if(height[i] >= height[k]){
                    sum -= (height[i] + height[k]);
                    ans += ((height[k] * (k - i - 1)) - sum);
                    sum = height[i]; k = i;
                }
            }
        }
        return ans;
    }
};