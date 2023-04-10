class Solution {
public:
    bool isValid(string str) {
        stack <char> s;
        for(auto x: str) {
            if(x == ')') {
                if(s.size() && s.top() == '(') s.pop();
                else return false;
            } else if(x == '}') {
                if(s.size() && s.top() == '{') s.pop();
                else return false;
            } else if(x == ']') {
                if(s.size() && s.top() == '[') s.pop();
                else return false;
            } else s.push(x);
        }
        return s.empty();
    }
};