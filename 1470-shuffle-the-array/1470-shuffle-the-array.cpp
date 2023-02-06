class Solution {
public:
	vector<int> shuffle(vector<int>& nums, int n) {
		int i = 0, j = n;
		while (j < 2 * n) {
			nums[i] <<= 10;
			nums[i] |= nums[j];
			i++; j++;
		}

		i = n - 1; j = (2 * n) - 1;
		while (i >= 0) {
			nums[j] = (nums[i] & ((1 << 10) - 1));
			nums[j - 1] = (nums[i] >> 10);
			i--; j -= 2;
		}

		return nums;
	}
};