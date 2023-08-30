class Solution {
public:
    long long minimumReplacement(vector <int> &arr) {
        long long n = arr.size(), ans = 0, prev = 1e9;
        for(int i = n - 1; i >= 0; i--) {
            if(prev > arr[i]) {
                prev = arr[i];
                continue;
            }
            
            long long que = arr[i] / prev,
                rem = arr[i] % prev,
                cnt = que + (rem != 0);
            ans += (cnt - 1);
            prev = arr[i] / cnt;
        }
        return ans;
    }
};