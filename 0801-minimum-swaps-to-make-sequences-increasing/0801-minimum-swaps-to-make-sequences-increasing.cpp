class Solution {
public:
    int findMin(int a, int b, int c, int d, int x, int y) {
        int ans = 1e9;
        if(a > c && b > d) ans = min(ans, x);
        if(a > d && b > c) ans = min(ans, y);
        return ans;
    }
    
    int minSwap(vector <int> &nums1, vector<int> &nums2) {
        int n = nums1.size(), a = 0, b = 1;
        for(int i = 1; i < n; i++) {
            int c = findMin(nums1[i], nums2[i], nums1[i - 1], nums2[i - 1], a, b);
            int d = 1 + findMin(nums2[i], nums1[i], nums1[i - 1], nums2[i - 1], a, b);
            a = c; b = d;
        }
        return min(a, b);
    }
};