class Solution {
public:
	string robotWithString(string s) {
		int n = s.size();
		vector <char> _min(n + 1, 'z');
		for (int i = n - 1; i >= 0; i--) _min[i] = min(s[i], _min[i + 1]);

        string ans;
		stack <char> st;
		for (int i = 0; i < n; i++) { 
            while (!st.empty() && st.top() <= _min[i]) {
                ans.push_back(st.top());
                st.pop(); 
            } st.push(s[i]);
		}

		while (!st.empty()) {
			ans.push_back(st.top());
			st.pop();
		}
        return ans;
	}
};