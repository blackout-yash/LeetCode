class Solution {
public:
	bool checkInclusion(string s1, string s2) {
		int size = 0, j = 0;
		vector <int> freq(26);
		for (auto x : s1) {
			if (freq[x - 'a']) freq[x - 'a']++;
			else {
				size++;
				freq[x - 'a']++;
			}
		}

		for (int i = 0; i < s2.size(); i++) {
			freq[s2[i] - 'a']--;
			if (freq[s2[i] - 'a'] == 0) size--;
			else if (freq[s2[i] - 'a'] == -1) {
				while (i >= j && freq[s2[i] - 'a'] == -1) {
					if (freq[s2[j] - 'a']) freq[s2[j] - 'a']++;
					else {
						size++;
						freq[s2[j] - 'a']++;
					} j++;
				}
            }

			if (!size) return true;
		}

		return false;
	}
};