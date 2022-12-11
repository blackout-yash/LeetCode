class Allocator {
public:
	vector <int> mem;
	Allocator(int n) {
		mem.resize(n, -1);
	}

	int allocate(int size, int mID) {
		int temp = 0;
		for (int i = 0; i < mem.size(); i++) {
			if (mem[i] == -1) temp++;
			else temp = 0;

			if (temp == size) {
				int range = size;
				for (int j = i; j >= 0; j--) {
					if (range) {
						mem[j] = mID;
						range--;
					} else break;
				}
				return ((i + 1) - size);
			}
		}
		return -1;
	}

	int free(int mID) {
		int cnt = 0;
		for (auto &x : mem) {
			if (x == mID) {
				x = -1;
				cnt++;
			}
		}
		return cnt;
	}
};

/**
 * Your Allocator object will be instantiated and called as such:
 * Allocator* obj = new Allocator(n);
 * int param_1 = obj->allocate(size,mID);
 * int param_2 = obj->free(mID);
 */