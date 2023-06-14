#define ll long long
class SGTree {
public:
	vector <int> seg;
	SGTree(int n) {
		seg.resize((4 * n) + 1, -1e9);
	}

	int query(int ind, int low, int high, int l, int r) {
		if (r < low || high < l) return -1e9;
		if (low >= l && high <= r) return seg[ind];

		int mid = low + (high - low) / 2;
		int left = query(2 * ind + 1, low, mid, l, r);
		int right = query(2 * ind + 2, mid + 1, high, l, r);

		return max(left, right);
	}

	void update(int ind, int low, int high, int i, int val) {
		if (low == high) {
			seg[ind] = val;
			return;
		}

		int mid = low + (high - low) / 2;
		if (i <= mid) update(2 * ind + 1, low, mid, i, val);
		else update(2 * ind + 2, mid + 1, high, i, val);

		seg[ind] = max(seg[2 * ind + 1], seg[2 * ind + 2]);
	}
};

class Solution {
public:
    int shortestSubarray(vector <int> &nums, int k) {
        ll n = nums.size(), curr = 0;
        map <ll, int> m, ind; m[0] = -1;
        for(int i = 0; i < n; i++) {
            curr += nums[i];
            m[curr] = i;
        }
        
        int i = 0;
        for(auto x: m) ind[x.first] = i++;
        
        ll ans = 1e9, prev = 0;
        SGTree seg(n);
        seg.update(0, 0, n - 1, ind[0], -1);
        for(int i = 0; i < n; i++) {
            prev += nums[i];
            ll req = prev - k;
            auto it = m.upper_bound(req); 
            if(it == m.begin()) {}
            else {
                it--;

                ll num = it -> first,
                    range = seg.query(0, 0, n - 1, 0, ind[num]);
                if(range == -1e9) {}
                else {
                    ll curr = i - range;
                    ans = min(ans, curr);
                }
            }
            seg.update(0, 0, n - 1, ind[prev], i);
        }
        if(ans == 1e9) return -1;
        return ans;
    }
};