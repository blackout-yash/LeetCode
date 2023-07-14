class Solution {
public:
    int longestSubsequenceUtil(vector<int>& arr, int difference) {
        int ans = 0;
        unordered_map <int, int> m;
        for(auto x: arr) {
            int num = x - difference,
                curr = m[num] + 1;
            m[x] = curr;
            ans = max(ans, curr);
        }
        return ans;
    }
    
    int longestSubsequence(vector<int>& arr, int difference) {
        int ans1 = longestSubsequenceUtil(arr, difference);
        // reverse(begin(arr), end(arr));
        int ans2 = longestSubsequenceUtil(arr, difference);
        return max(ans1, ans2);
    }
};