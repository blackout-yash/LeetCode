#define ll long long
class Solution {
public:
    vector <ll> min(int i, int n, int fact, vector <int> &nums) {
        stack <ll> st;
        vector <ll> ans(n, i);
        while(i >= 0 && i < n) {
            while(st.size()) {
                if(nums[i] > nums[st.top()]) {
                    ans[i] = st.top() + fact;
                    break;
                }
                st.pop();
            }
            st.push(i);
            i += fact;
        }
        return ans;
    }
    
    ll findSum(int i, int j, vector <ll> &sum) {
        ll ans = sum[j];
        if(i) ans -= sum[i - 1];
        return ans;
    }
    
    int maxSumMinProduct(vector<int>& nums) {
        int n = nums.size();
        vector <ll> prefix = min(0, n, 1, nums);
        vector <ll> suffix = min(n - 1, n, -1, nums);
        vector <ll> sum(n);
        for(int i = 0; i < n; i++) {
            if(i) sum[i] = sum[i - 1] + nums[i];
            else sum[i] = nums[i];
        }
        
        ll ans = 0, mod = 1e9 + 7;
        for(int i = 0; i < n; i++) {
            int l = prefix[i], 
                r = suffix[i];
            ans = max(ans, (1ll * nums[i] * findSum(l, r, sum)));
        }
        return ans % mod;
    }
};