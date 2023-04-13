class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        stack <int> s;
        int i = 0, j = 0, n = pushed.size();
        while(i < n) {
            s.push(pushed[i]);
            while(s.size() && s.top() == popped[j]) {
                s.pop(); j++;
            } i++;
        }
        
        while(s.size()) {
            if(s.top() != popped[j]) return false;
            s.pop(); j++;
        }
    
        return true;
    }
};