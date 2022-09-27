class Solution {
public:
	string pushDominoes(string dominoes) {
		int prev = -1, n = dominoes.size();
		for (int i = 0; i < n; i++) {
			if (dominoes[i] == 'R') {
				int j = i + 1;
				while (true) {
					if (j == n || dominoes[j] != '.') break;
					j++;
				} prev = j;
                
				if (j != n && dominoes[j] == 'L') {
					int cnt = ((j - i) + 1) / 2, range = cnt, flag = 0;
					if (((j - i) + 1) & 1) flag = 1;
					for (int k = i; k <= j; k++) {
						if (cnt) dominoes[k] = 'R', cnt--;
						else dominoes[k] = 'L';
					}
					if (flag) dominoes[i + range] = '.';
					i = j;
				} else {
					for (int k = i; k <= j; k++) dominoes[k] = 'R';
					if (i + 1 == n) break;
					else i = j - 1;
				}
			} else if(dominoes[i] == 'L') {
				int j = i;
				while (true) {
					if (prev == j) break;
					dominoes[j--] = 'L';
				}
			}
		}
		return dominoes;
	}
};