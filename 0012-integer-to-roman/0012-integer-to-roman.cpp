class Solution {
public:
	string intToRoman(int num) {
		vector <int> value = {1, 4, 5, 9, 10, 40, 50, 90, 100, 400, 500, 900, 1000};
		vector <string> symbol = {"I", "IV", "V", "IX", "X", "XL", "L", "XC" , "C", "CD", "D", "CM", "M"};

		string ans;
		while (num) {
			for (int i = value.size() - 1; i >= 0; i--) {
				if (num >= value[i]) {
					num -= value[i];
					ans += symbol[i];
					i++;
				}
			}
		}

		return ans;
	}
};