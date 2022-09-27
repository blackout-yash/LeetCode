class Solution {
public:
    string pushDominoes(string dominoes) {
        int n = dominoes.size();
        vector <int> left(n), right(n);
        for(int i = n - 1; i >= 0; i--){
            if(dominoes[i] == 'L') left[i] = 1;
            else if(i + 1 != n && left[i + 1]) {
                if(dominoes[i] == 'R') left[i] = 0;
                else left[i] = 1 + left[i + 1];
            }
        }
        
        for(int i = 0; i < n; i++){
            if(dominoes[i] == 'R') right[i] = 1;
            else if(i && right[i - 1]) {
                if(dominoes[i] == 'L') right[i] = 0;
                else right[i] = 1 + right[i - 1];
            }
        }
        
        string ans(n, '.');
        for(int i = 0; i < n; i++){
            if(left[i] && left[i] < right[i]) ans[i] = 'L';
            else if(right[i] && left[i] > right[i]) ans[i] = 'R';
            else if(left[i] > right[i]) ans[i] = 'L';
            else if(left[i] < right[i]) ans[i] = 'R';
        }
        
        return ans;
    }
};