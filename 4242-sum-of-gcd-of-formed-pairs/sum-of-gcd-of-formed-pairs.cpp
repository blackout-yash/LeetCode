class Solution {
public:
    long long gcdSum(vector <int> &nums) {
        int mx = nums[0];
        vector <int> arr;
        for(auto x: nums) {
            mx = max(x, mx);
            arr.push_back(__gcd(mx, x));
        } sort(begin(arr), end(arr));

        long long sum = 0, i = 0, j = arr.size() - 1;
        while(i < j) sum += __gcd(arr[i++], arr[j--]);
        return sum;
    }
};