class Solution {
public:
    int jump(vector <int> &nums) {
        int ind = 0, step = 0, next = 0, n = nums.size();
        for(int i = 0; i < n; i++) {
            next = max(next, i + nums[i]);
            if(i + 1 != n && i == ind) {
                step++;
                ind = next;
            }
        }
        return step;
    }
};