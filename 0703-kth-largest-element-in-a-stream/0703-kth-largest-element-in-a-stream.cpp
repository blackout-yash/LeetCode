class KthLargest {
public:
    int k;
    priority_queue <int, vector <int>, greater <int>> pq;
    
    KthLargest(int k, vector <int> &nums) {
        this -> k = k;
        for(auto x: nums) pq.push(x);
    }
    
    int add(int val) {
        pq.push(val);
        while(k < pq.size()) pq.pop();
        return pq.top();
    }
};
/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */