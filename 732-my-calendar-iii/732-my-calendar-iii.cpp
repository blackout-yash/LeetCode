class MyCalendarThree {
public:
    map <int, int> m;
    MyCalendarThree() {}
    
    int book(int start, int end) {
        m[start]++;
        m[end]--;
        
        int _max = 0, ans = 0;
        for(auto x: m){
            _max += x.second;
            ans = max(ans, _max);
        }
        return ans;
    }
};

/**
 * Your MyCalendarThree object will be instantiated and called as such:
 * MyCalendarThree* obj = new MyCalendarThree();
 * int param_1 = obj->book(start,end);
 */