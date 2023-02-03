class Solution {
public:
	string convert(string s, int numRows) {
		vector <vector<char>> arr(numRows);
		int j = 0, flag = 1;
		for (auto x : s) {
			arr[j].push_back(x);
			
            if(numRows != 1) j += flag;
			if (j == numRows) {
				j -= 2;
				flag = -1;
			} if (j == 0) flag = 1;
		}
		string ans;
		for (auto x : arr) {
			for (auto y : x) ans.push_back(y);
		}
		return ans;
	}
};