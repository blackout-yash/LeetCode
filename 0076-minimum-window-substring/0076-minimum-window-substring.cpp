class Solution {
public:
	string minWindow(string s, string t) {
		map <char, int> freq, temp;
		for (auto x : t) freq[x]++;

		int n = s.size(), curr = t.size(), j = 0, start = -1, end = -1, size = 1e9;
		for (int i = 0; i < n; i++) {
			if (curr && freq[s[i]] > temp[s[i]]) curr--;
			temp[s[i]]++;
			if (!curr) {
				while (i >= j) {
					if (!curr) {
						int currSize = (i - j) + 1;
						if (size > currSize) {
							size = currSize;
							start = j;
							end = i;
						}
					} else break;

					if (freq[s[j]] && freq[s[j]] >= temp[s[j]]) break;
					else temp[s[j]]--;
					j++;
				}
			}
		}
        
        if(start == -1) return "";
		return s.substr(start, size);
	}
};