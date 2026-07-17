class Solution {
public:
    double findMedianSortedArrays(vector <int> &nums1, vector<int> &nums2) {
        vector <int> arr;
        int n = nums1.size(), m = nums2.size(), i = 0, j = 0;
        while(i < n && j < m) {
            if(nums1[i] < nums2[j]) arr.push_back(nums1[i++]);
            else arr.push_back(nums2[j++]);
        }

        while(i < n) arr.push_back(nums1[i++]);
        while(j < m) arr.push_back(nums2[j++]);

        int size = arr.size();
        if(size & 1) return arr[size / 2];
        return (double) (arr[(size - 1) / 2] + arr[size / 2]) / 2;
    }
};