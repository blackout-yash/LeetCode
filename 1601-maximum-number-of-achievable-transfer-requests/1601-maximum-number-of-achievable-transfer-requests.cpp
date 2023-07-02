class Solution {
public:
    int maximumRequests(int n, vector<vector<int>>& requests) {
        vector <int> res;
        int len = requests.size(), total = pow(2, len), _max = 0;
        for(int i = 0; i <= total; i++){
            vector <int> req;
            for(int j = 0; j < len; j++){
                if((i >> j) & 1) req.push_back(j);
            }
            
            vector <int> degree(n);
            for(auto j:req){
                degree[requests[j][0]]++;
                degree[requests[j][1]]--;
            }
            
            for(auto j:degree) {
                if(j!=0) {
                    req.clear();
                    break;
                }
            }
            
            _max = max(_max, (int)req.size());
        }
        return _max;
    }
};