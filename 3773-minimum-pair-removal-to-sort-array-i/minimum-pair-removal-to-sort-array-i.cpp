class Solution {
public:
    bool isNonDecreasing(vector <int> &nums) {
        int prev = INT_MIN;
        for(auto x: nums) {
            if(prev > x) return false;
            prev = x;
        }
        return true;
    }

    int minimumPairRemoval(vector <int> &nums) {
        int ans = 0;
        while(!isNonDecreasing(nums)) {
            ans++;

            int sum = INT_MAX, ind = 0; 
            for(int i = 0; i < nums.size() - 1; i++) {
                int curr = nums[i] + nums[i + 1];
                if(sum > curr) {
                    sum = curr;
                    ind = i;
                }
            }

            vector <int> tmp;
            for(int i = 0; i < nums.size(); i++) {
                if(i == ind) {
                    tmp.push_back(nums[i] + nums[i + 1]);
                    i++;
                } else tmp.push_back(nums[i]);
            }
            nums = tmp;
        }
        return ans;
    }
};