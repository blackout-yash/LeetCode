class Solution {
public:
    string predictPartyVictory(string senate) {
        queue <int> q1, q2;
        int n = senate.length();
        for(int i = 0; i < n; i++) (senate[i] == 'R') ? q1.push(i) : q2.push(i);
        
        while(!q1.empty() && !q2.empty()){
            int one = q1.front(), two = q2.front();
            q1.pop(); q2.pop();
            (one < two) ? q1.push(one + n) : q2.push(two + n);
        }
        
        return (q1.size()) ? "Radiant" : "Dire";
    }
};