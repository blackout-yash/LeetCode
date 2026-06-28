class Solution {
public:
    int maximumElementAfterDecrementingAndRearranging(vector <int> &arr) {
        int ans = 0, curr = 0;
        sort(begin(arr), end(arr));
        for(auto x: arr) {
            if(x > curr) {
                curr++;
                ans = curr;
            }
        }
        return ans;
    }
};