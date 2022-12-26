class Solution {
public:
    bool canJump(vector<int> &nums) {
        int ind = 0;
        for(int i = 0; i < nums.size(); i++) {
            if(ind + 1 == i) return false;
            ind = max(ind, nums[i] + i);
        }
        return true;
    }
};