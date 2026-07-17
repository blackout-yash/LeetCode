class Solution {
public:
    double findMedianSortedArrays(vector <int> &nums1, vector<int> &nums2) {
        int n = nums1.size(), m = nums2.size(), i = 0, j = 0, isEven = 0, 
            first = (n + m - 1) / 2, second = (n + m) / 2, sum = 0, ind = -1;

        while(i < n || j < m) {
            int curr = -1;
            if(i < n && j < m) {
                if(nums1[i] < nums2[j]) curr = nums1[i++];
                else curr = nums2[j++];
            } else if(i < n) curr = nums1[i++];
            else curr = nums2[j++];

            ind++;
            if(ind == first) sum += curr;
            else if(ind == second) {
                sum += curr;
                isEven = 1;
                break;
            }
        }

        if(!isEven) return sum;
        return (double) sum / 2;
    }
};