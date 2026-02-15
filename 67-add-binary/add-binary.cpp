class Solution {
public:
    string addBinary(string a, string b) {
        string ans;
        int n = a.size(), m = b.size(), i = n - 1, j = m - 1, carry = 0;
        while(i >= 0 && j >= 0) {
            if(a[i] == '1') {
                if(b[j] == '1') {
                    if(carry == 1) ans.push_back('1');
                    else {
                        ans.push_back('0');
                        carry = 1;
                    }
                } else {
                    if(carry == 1) ans.push_back('0');
                    else ans.push_back('1');
                }
            } else {
                if(b[j] == '1') {
                    if(carry == 1) ans.push_back('0');
                    else ans.push_back('1');
                } else {
                    if(carry == 1) {
                        ans.push_back('1');
                        carry = 0;
                    } else ans.push_back('0');
                }
            }
            i--; j--;
        }

        while(i >= 0) {
            if(carry) {
                if(a[i] == '1') ans.push_back('0');
                else {
                    ans.push_back('1');
                    carry = 0;
                }
            } else ans.push_back(a[i]);
            i--;
        }

        while(j >= 0) {
            if(carry) {
                if(b[j] == '1') ans.push_back('0');
                else {
                    ans.push_back('1');
                    carry = 0;
                }
            } else ans.push_back(b[j]);
            j--;
        }

        if(carry) ans.push_back('1');
        reverse(begin(ans), end(ans));
        return ans;
    }
};