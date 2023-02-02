class Solution {
public:
    bool isAlienSorted(vector <string> &words, string order) {
        vector <int> arr(26);
        for (int i = 0; i < 26; i++) arr[order[i] - 'a'] = i;

        int n = words.size(), prev = -1;
        for (int i = 0; i < n; i++) {
            if (arr[words[i][0] - 'a'] > prev) prev = arr[words[i][0] - 'a'];
            else if (arr[words[i][0] - 'a'] == prev) {
                int cnt = 0, range = min(words[i - 1].size(), words[i].size());
                for (int j = 0; j < range; j++) {
                    int temp1 = arr[words[i - 1][j] - 'a'],
                        temp2 = arr[words[i][j] - 'a'];
                    if (temp1 == temp2)
                        cnt++;
                    else if (temp1 > temp2) return false;
                    else break;
                }
                if (cnt == range) {
                    if (words[i - 1].size() > words[i].size()) return false;
                }
            } else return false;
        }
        return true;
    }
};