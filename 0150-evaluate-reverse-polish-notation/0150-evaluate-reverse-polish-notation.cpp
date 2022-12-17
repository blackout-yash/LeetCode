#define ll long long
class Solution {
public:
	vector <ll> solve(stack <ll> &s) {
		vector <ll> arr;
		while (arr.size() != 2) {
			arr.push_back(s.top());
			s.pop();
		}
		return arr;
	}

	int evalRPN(vector <string> &tokens) {
		stack <ll> s;
		for (auto x : tokens) {
			if (x == "+") {
				vector <ll> arr = solve(s);
				s.push(arr[1] + arr[0]);
			} else if (x == "-") {
				vector <ll> arr = solve(s);
				s.push(arr[1] - arr[0]);
			} else if (x == "*") {
				vector <ll> arr = solve(s);
				s.push(arr[1] * arr[0]);
			} else if (x == "/") {
				vector <ll> arr = solve(s);
				s.push(arr[1] / arr[0]);
			} else s.push(stoi(x));
		}

		return s.top();
	}
};