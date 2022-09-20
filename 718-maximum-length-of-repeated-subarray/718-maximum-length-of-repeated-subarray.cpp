class Solution {
public:
    int findLength(int n, int m, vector<int> &nums1, vector<int> &nums2) {
        int ans = 0;
        for(int i = 0; i < n; i++){
            int j = i, k = m - 1, cnt = 0;
            while(true){
                if(j == -1 || k == -1) break;
                else if(nums1[j] == nums2[k]) cnt++;
                else cnt = 0;
                j--; k--;
                ans = max(ans, cnt);
            }
        }
        return ans;
    }
    
    int findLength(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size(), m = nums2.size();
        
        int ans1 = findLength(n, m, nums1, nums2);
        int ans2 = findLength(m, n, nums2, nums1);
        
        return max(ans1, ans2);
    }
};