class LSGTree {
public:
	vector<long long> tree, lazy;
	LSGTree(int n) {
		tree.resize(4 * n + 1);
		lazy.resize(4 * n + 1);
	}

	long long query(int ind, int start, int end, int i, int j) {
		if (lazy[ind] != 0) {
			tree[ind] += (end - start + 1) * lazy[ind];
			if (start != end) {
				lazy[ind * 2 + 1] += lazy[ind];
				lazy[ind * 2 + 2] += lazy[ind];
			}
			lazy[ind] = 0;
		}

		if (start > end || start > j || end < i) return 0;

		if (start >= i && end <= j)
			return tree[ind];

		int mid = start + (end - start) / 2;
		long long left = query(2 * ind + 1, start, mid, i, j);
		long long right = query(2 * ind + 2, mid + 1, end, i, j);
		return (left + right);
	}

	void update(int ind, int start, int end, int i, int j, int val) {
		if (lazy[ind] != 0) {
			tree[ind] += (end - start + 1) * lazy[ind];
			if (start != end) {
				lazy[ind * 2 + 1] += lazy[ind];
				lazy[ind * 2 + 2] += lazy[ind];
			}
			lazy[ind] = 0;
		}

		if (start > end || start > j || end < i) return;

		if (start >= i && end <= j) {
			tree[ind] += (end - start + 1) * val;
			if (start != end) {
				lazy[ind * 2 + 1] += val;
				lazy[ind * 2 + 2] += val;
			}
			return;
		}

		int mid = start + (end - start) / 2;
		update(ind * 2 + 1, start, mid, i, j, val);
		update(ind * 2 + 2, mid + 1, end, i, j, val);
		tree[ind] = tree[ind * 2 + 1] + tree[ind * 2 + 2];
	}
};

class Solution {
public:
    string shiftingLetters(string s, vector<vector<int>> &shifts) {
        int n = s.size();
        
        LSGTree lgs(n);
        for(auto x: shifts) {
            int fact = -1;
            if(x[2]) fact = 1;
            lgs.update(0, 0, n - 1, x[0], x[1], fact);
        }
        
        for(int i = 0; i < n; i++) {
            long long curr = lgs.query(0, 0, n - 1, i, i),
                temp = (((s[i] - 'a' + curr) % 26) + 26) % 26;
            s[i] = (char) 'a' + temp;
        }
        return s;
    }
};