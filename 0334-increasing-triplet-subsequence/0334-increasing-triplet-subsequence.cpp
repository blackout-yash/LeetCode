class Solution {
public:
	bool increasingTriplet(vector <int> &nums) {
		int one = INT_MAX, two = INT_MAX;
		for (auto x : nums) {
			if(one >= x) one = x;
            else if(two >= x) two = x;
            else return 1;
		}
		return 0;
	}
};