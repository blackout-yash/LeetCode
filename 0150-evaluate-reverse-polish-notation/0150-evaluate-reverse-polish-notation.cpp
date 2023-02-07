class Solution {
public:
	bool isOperator(string &s) {
		return (s == "/" || s == "*" || s == "+" || s == "-");
	}

	int evalRPN(vector <string> &tokens) {
		stack <int> s;
		for (int i = 0; i < tokens.size(); i++) {
			if (!isOperator(tokens[i])) s.push(stoi(tokens[i]));
			else {
        		int right = s.top();
				s.pop();
        		int left = s.top();
				s.pop();

				if (tokens[i] == "/") s.push(left / right);
				else if (tokens[i] == "*") s.push(left * right);
				else if (tokens[i] == "+") s.push(left + right);
				else s.push(left - right);
			}
		}
		return s.top();
	}
};