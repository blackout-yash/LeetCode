class BrowserHistory {
public:
    int curr;
    vector<string> arr;
    BrowserHistory(string homepage) {
        arr.push_back(homepage);
        curr = 0;
    }
    
    void visit(string url) {
        int l = arr.size()-1;
        while(l > curr){
            arr.pop_back();
            l--;
        }
        curr++;
        arr.push_back(url);
    }
    
    string back(int steps) {
        curr -= steps;
        if(curr < 0) curr = 0;
        return arr[curr];
    }
    
    string forward(int steps) {
        curr += steps;
        if(curr >= arr.size()) curr = arr.size() - 1;
        return arr[curr];
    }
};