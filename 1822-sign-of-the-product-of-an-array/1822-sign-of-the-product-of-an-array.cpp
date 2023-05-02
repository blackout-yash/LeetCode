class Solution {
public:
    int arraySign(vector <int> &nums) {
        int pro = 1;
        for(auto x: nums) {
            pro *= x;
            if(pro > 0) pro = 1;
            else if(pro < 0) pro = -1;
            else pro = 0;
        }
        
        return pro;
    }
};