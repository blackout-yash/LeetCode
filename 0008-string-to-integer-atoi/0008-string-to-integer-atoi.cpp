class Solution {
public:
	long isRange(long n) {
		long range = (1ll << 31);
		if (n < -range) return -range;
		else if (n >= range) return range;
		return n;
	}

	int toInt(char ch) {
		int ans = ch - '0';
		return ans;
	}

	long myAtoiUtil(int i, int &j, int n, bool start, string &s) {
		if (i == n) return 0;

		if (start) {
			if ('0' > s[i] || '9' < s[i]) return 0;
		} else {
			if (s[i] == ' ') return myAtoiUtil(i + 1, j, n, 0, s);
		}

		long ans = myAtoiUtil(i + 1, j, n, 1, s);

		if (s[i] == '-') ans *= -1;
		else if (s[i] == '+') ans *= 1;
		else if ('0' <= s[i] && s[i] <= '9') ans += ceil(pow(10, j++)) * toInt(s[i]);
		else ans = 0; j = min(10, j);
        
		return isRange(ans);
	}

	int myAtoi(string s) {
		int n = s.size(), j = 0;
		long ans = myAtoiUtil(0, j, n, 0, s);
        if(ans == (1ll << 31)) ans--;
		return ans;
	}
};