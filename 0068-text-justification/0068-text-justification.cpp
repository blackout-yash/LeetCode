class Solution {
public:
    vector <string> fullJustify(vector <string> &s, int maxWidth) {
        int n = s.size();
        vector <string> ans;
        for(int i = 0; i < n; ) {
            int space = 0, extraSpace = 0, total = 0, j = i, ind = j, cnt = 0;
            while(j < n) {
                if(i == j) {
                    ind = j; cnt = 1;
                    total = s[j].size();
                    space = maxWidth - total;
                } else {
                    int curr = total + s[j].size(),
                        left = maxWidth - curr;
                    if(left < cnt) break;
                    else {
                        ind = j;
                        space = left / cnt;
                        extraSpace = left % cnt;
                    }
                    cnt++; total += s[j].size();
                }
                j++;
            }
            
            string temp;
            while(i <= ind) {
                temp += s[i++];
                int range = space;
                if(ind + 1 == n) {
                    if(maxWidth > temp.size()) temp.push_back(' ');
                    while(i == n && maxWidth > temp.size()) temp.push_back(' ');
                } else {
                    while(range-- && maxWidth > temp.size()) temp.push_back(' ');
                        if(extraSpace) {
                            temp.push_back(' ');
                            extraSpace--;
                        }
                    }
                }
            ans.push_back(temp);
        }
        return ans;
    }
};