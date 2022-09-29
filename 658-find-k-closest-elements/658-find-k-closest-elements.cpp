class Solution {
public:
    vector<int> findClosestElements(vector<int> &arr, int k, int x) {
        int n = arr.size(), low = 0, high = n - 1, start = high, diff = 1e9;
        while(low <= high){
            int mid = low + (high - low) / 2, num = arr[mid];
            
            if(num == x) {
                start = mid;
                break;
            } else if(num > x) high = mid - 1;
            else low = mid + 1;
            
            if(diff >= abs(num - x)) {                
                if(diff == abs(num - x)) start = min(start, mid);
                else start = mid;
                diff = abs(num - x);
            }
        }  
        
        int i = start, j = start;
        while(true){
            if(j - i == k - 1) break;
            else if(!i) j++;
            else if(j + 1 == n) i--;
            else {
                if(abs(arr[i - 1] - x) <= abs(arr[j + 1] - x)) i--;
                else j++;
            }
        }
        
        vector <int> ans;
        for(int k = i; k <= j; k++) ans.push_back(arr[k]);
        
        return ans;
    }
};