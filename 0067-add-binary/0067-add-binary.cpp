class Solution {
public:
	void update(int i, int &prev, string &ans, string &a) {
		while (i >= 0) {
			if (prev) {
				if (a[i] == '1') ans.push_back('0');
				else {
					prev = 0;
					ans.push_back('1');
				}
			} else ans.push_back(a[i]);
			i--;
		}
	}

	string addBinary(string &a, string &b) {
		string ans;
		int i = a.size() - 1, j = b.size() - 1, prev = 0;
		while (i >= 0 && j >= 0) {
			if (a[i] == b[j]) {
				if (prev) {
					ans.push_back('1');
					if (a[i] == '0') prev = 0;
				} else {
					ans.push_back('0');
					if (a[i] == '1') prev = 1;
				}
			} else {
				if (prev) ans.push_back('0');
				else ans.push_back('1');
			} i--; j--;
		}

		update(i, prev, ans, a);
		update(j, prev, ans, b);

		if (prev) ans.push_back('1');
		reverse(ans.begin(), ans.end());
		
		return ans;
	}
};