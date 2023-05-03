class Solution {
public:
    vector <int> isFind(vector<int> &nums1, vector<int> &nums2) {
        vector <int> ans;
        for(auto x: nums1) {
            auto it = lower_bound(nums2.begin(), nums2.end(), x);
            if((it == nums2.end() || *it != x) && (ans.empty() || ans.back() != x)) ans.push_back(x);
        }
        return ans;
    }
    
    vector<vector<int>> findDifference(vector<int> &nums1, vector<int> &nums2) {
        sort(nums1.begin(), nums1.end());
        sort(nums2.begin(), nums2.end());
        
        vector <int> ans1 = isFind(nums1, nums2), 
                     ans2 = isFind(nums2, nums1);
        
        return {ans1, ans2};
    }
};