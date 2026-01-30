class Solution {
public:
    vector<int> rotateElements(vector<int>& nums, int k) {
        vector<int> positions, values;
        for (int i = 0; i < (int)nums.size(); ++i) {
            if (nums[i] >= 0) {
                positions.push_back(i);
                values.push_back(nums[i]);
            }
        }

        if (positions.size() == 0) 
            return nums;

        k %= positions.size();

        // Shift values k left
        vector<int> rotated;
        rotated.reserve(values.size());
        for (int i = k; i < (int)values.size(); ++i) 
            rotated.push_back(values[i]);
        for (int i = 0; i < k; ++i) 
            rotated.push_back(values[i]);

        for (int t = 0; t < (int)positions.size(); ++t) {
            nums[positions[t]] = rotated[t];
        }

        return nums;
    }
};