// cross product of two collinear vectors is equal to zero vector
// a × b =|a| |b| sin θ
class Solution {
public:
    bool checkStraightLine(vector<vector<int>>& coordinates) {
        int x1 = coordinates[0][0] - coordinates[1][0],
            y1 = coordinates[0][1] - coordinates[1][1];
        for(int i = 2; i < coordinates.size(); i++) {
            int x2 = coordinates[0][0] - coordinates[i][0],
                y2 = coordinates[0][1] - coordinates[i][1];
            if((x1 * y2) - (y1 * x2)) return false;
        }
        return true;
    }
};