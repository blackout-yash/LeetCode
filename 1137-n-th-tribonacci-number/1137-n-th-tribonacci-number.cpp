class Solution {
public:
    int tribonacci(int n) {
        int arr[] = {0, 1, 1};
        for(int i = 3; i <= n; i++) {
            int curr = arr[0] + arr[1] + arr[2];
            arr[0] = arr[1];
            arr[1] = arr[2];
            arr[2] = curr;
        }
        if(n <= 2) return arr[n];
        return arr[2];
    }
};