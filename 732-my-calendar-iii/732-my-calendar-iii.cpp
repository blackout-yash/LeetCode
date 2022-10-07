#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>

using namespace __gnu_pbds;

typedef tree<pair<int, int>, null_type, less<pair<int, int>>, rb_tree_tag, tree_order_statistics_node_update > multipbds;

class MyCalendarThree {
public:
    int i;
    set <int> s;
    multipbds l, r;
	MyCalendarThree() {i = 0;}

	int book(int start, int end) {
		end = end - 1;
		s.insert(end);
		s.insert(start);
		l.insert({start, i});
		r.insert({end, 1e9 - i});
        i++;

		int ans = 0;
		for (auto x : s) {
            int cnt = (r.size() - r.order_of_key({x, 0}));
			cnt -= (l.size() - l.order_of_key({x, 1e9}));
            ans = max(ans, cnt);
		}

		return ans;
	}
};

/**
 * Your MyCalendarThree object will be instantiated and called as such:
 * MyCalendarThree* obj = new MyCalendarThree();
 * int param_1 = obj->book(start,end);
 */