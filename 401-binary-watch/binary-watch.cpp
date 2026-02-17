class Solution {
public:
    int bit(int n) {
        int cnt = 0;
        while(n) {
            if(n & 1) cnt++;
            n /= 2;
        }
        return cnt;
    }

    vector <string> readBinaryWatch(int turnedOn) {
        vector <string> ans;
        for(int i = 0; i < 12; i++) {
            for(int j = 0; j < 60; j++) {
                if(bit(i) + bit(j) == turnedOn) {
                    string curr = to_string(i) + ":";
                    if(j < 10) curr.push_back('0');
                    curr += to_string(j);
                    ans.push_back(curr);
                }
            }
        }
        return ans;
    }
};