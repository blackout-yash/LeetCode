class Solution {
public:
    bool validPartition(vector <int> &nums) {
        int n = nums.size(), ans1 = 1, ans2 = 1, ans3 = 1, ans4 = 1;
        for(int i = 0; i < n; i++) {
            bool curr1 = 0, curr2 = 0;
            if(i && nums[i] == nums[i - 1]) curr1 = ans2;
            
            if(i >= 2 && 
              ((nums[i] == nums[i - 1] && nums[i] == nums[i - 2]) ||
               (nums[i] - nums[i - 1] == 1 && nums[i - 1] - nums[i - 2] == 1))) curr2 = ans1;
            
            ans1 = ans2;
            ans2 = ans3;
            ans3 = (curr1 | curr2);
        }
        return ans3;
    }
};