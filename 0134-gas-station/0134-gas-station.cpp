class Solution {
public:
	int canCompleteCircuit(vector<int> &gas, vector<int> &cost) {
		int i = 0, j = 0, n = gas.size(), curr, size = 0;
		while (i < n) {
			if (size == 0) curr = gas[i];
			if (curr >= cost[j]) {
				if (i == j && size) return i;
				curr += (gas[(j + 1) % n] - cost[j]);
				j++; j %= n; size++;
			} else {
				if (size == 0) i++, j++;
				else {
					while (i < n && curr < cost[j]) {
						curr += (cost[i] - gas[i]);
						i++; size--;
					}
				}
			}
		}
		return -1;
	}
};