class Solution {
public:
    vector<int> addToArrayForm(vector<int>& num, int k) {
        int carry = 0, i = num.size() - 1;
        while(i >= 0 && k) {
            int curr = num[i] + (k % 10) + carry;
            num[i] = curr % 10;
            carry = curr / 10; i--; k /= 10;
        }
        
        while(i >= 0) {
            int curr = num[i] + carry;
            num[i] = curr % 10;
            carry = curr / 10; i--;
        }
        
        k += carry;
        while(k) {
            num.insert(num.begin(), k % 10);
            k /= 10;
        }
        
        return num;
    }
};