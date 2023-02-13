class Solution {
public:
    int countOdds(int low, int high) {
        int left = (low / 2),
            right = (high / 2) + (high & 1);
        return right - left;
    }
};