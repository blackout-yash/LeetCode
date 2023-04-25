class SmallestInfiniteSet {
    unordered_map <int, bool> m;
public:
    SmallestInfiniteSet() {}
    
    int popSmallest() {
        for(int i = 1;; i++) {
            if(!m.count(i)) {
                m[i] = 1;
                return i;
            }
        }
    }
    
    void addBack(int num) {
        if(m.count(num)) m.erase(num);
    }
};

/**
 * Your SmallestInfiniteSet object will be instantiated and called as such:
 * SmallestInfiniteSet* obj = new SmallestInfiniteSet();
 * int param_1 = obj->popSmallest();
 * obj->addBack(num);
 */