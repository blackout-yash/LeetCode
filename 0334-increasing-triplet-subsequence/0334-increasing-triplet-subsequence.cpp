class Solution {
public:
	bool increasingTriplet(vector <int> &nums) {
		long one = -1e10, two = one - 1;
		for (auto x : nums) {
			if (one <= -1e10) one = x;
			else if (two <= -1e10) {
				if (one < x) two = x;
				else one = min(one, (long)x);
			} else if (two > x) {
				if (one < x) two = x;
                else one = min(one, (long)x);
			} else one = min(one, (long)x);
            
			if (one < two && two < x) return 1;
		}
		return 0;
	}
};