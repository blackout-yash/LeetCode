class Solution {
public:
    int trap(vector <int> &height) {
        int ans = 0, n = height.size();
        vector <int> prefix(n), suffix(n);
        for(int i = 0; i < n; i++) {
            if(i) prefix[i] = max(prefix[i - 1], height[i]);
            else prefix[i] = height[i];
        }
        for(int i = n - 1; i >= 0; i--) {
            if(i + 1 != n) suffix[i] = max(suffix[i + 1], height[i]);
            else suffix[i] = height[i];
        }
        for (int i = 0; i < n; i++) {
            int left = prefix[i],
                right = suffix[i];
            ans += max(0, (min(left, right) - height[i]));
        }
        return ans;
    }
};