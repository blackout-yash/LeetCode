class Solution {
public:
    int maximizeSquareHoleArea(int n, int m, vector <int> &hBars, vector <int> &vBars) {
        sort(begin(hBars), end(hBars));
        sort(begin(vBars), end(vBars));

        int hMax = 1, hCurr = 1;
        for(int i = 1; i < hBars.size(); i++) {
            if(hBars[i] - hBars[i - 1] == 1) hCurr++;
            else hCurr = 1;
            hMax = max(hMax, hCurr);
        }

        int vMax = 1, vCurr = 1;
        for(int i = 1; i < vBars.size(); i++) {
            if(vBars[i] - vBars[i - 1] == 1) vCurr++;
            else vCurr = 1;
            vMax = max(vMax, vCurr);
        }
        
        int size = min(hMax, vMax) + 1;
        return size * size;
    }
};