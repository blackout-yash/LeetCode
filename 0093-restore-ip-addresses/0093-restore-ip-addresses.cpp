class Solution {
public:
    vector <string> ans;
    void restoreIpAddressesUtil(int i, int num, int cnt, string &temp, string &s) {
        if (i == s.size()) {
            if (cnt == 3) ans.push_back(temp);
            return;
        }

        num *= 10; num += (s[i] - '0');
        if(temp.size() == 1 && temp.back() == '0') {}
        else if(temp.size() >= 2 && temp[temp.size() - 2] == '.' && temp.back() == '0') {}
        else if (0 <= num && num <= 255) {
            temp.push_back(s[i]);
            restoreIpAddressesUtil(i + 1, num, cnt, temp, s);
            temp.pop_back();
        }

        if (i && temp.back() != '.' && cnt < 3) {
            temp.push_back('.');
            restoreIpAddressesUtil(i, 0, cnt + 1, temp, s);
            temp.pop_back();
        }
    }

    vector <string> restoreIpAddresses(string s) {
        string temp;
        restoreIpAddressesUtil(0, 0, 0, temp, s);
        return ans;
    }
};