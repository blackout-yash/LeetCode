class Solution {
public:
	vector <char> numToChar(int n) {
		if (n <= 1) return {};
		vector <char> ans;
		while (n) {
			ans.push_back(char((n % 10) + '0'));
			n /= 10;
		}
		reverse(ans.begin(), ans.end());
		return ans;
	}

	int compress(vector <char> &chars) {
		int i = 0, j = 0, n = chars.size();
		while (i < n) {
            int size = 1;
			chars[j++] = chars[i++];
			while (i < n && chars[j - 1] == chars[i]) i++, size++;

			vector <char> temp = numToChar(size);
			for (auto x : temp) chars[j++] = x;
		}

		return j;
	}
};