// @author: aditya
class Solution {
public:
    bool pos(vector<int>v,long long int x){
        vector<long long>nums;
        for(auto i:v){
           nums.push_back((long long int )(i));
        }
        for(int i=nums.size()-1;i>=1;i--){
            
            if(nums[i]>=1&&nums[i]>x){
                long long rem=nums[i]-x;
                nums[i]=x;
                nums[i-1]+=rem;
            }
            // break;
        }
        // for(auto i:nums){
        //     cout<<i<<" ";
        // }
        // cout<<"\n";
        if(*max_element(nums.begin(),nums.end())<=x){
            return true;
        }
        return false;
    }
    int minimizeArrayValue(vector<int>& nums) {
     
        long long l=0,r=1e18;
        long long  mid;
        while(l<=r){
            mid=l+(r-l)/2;
            if(pos(nums,mid)){
                r=mid-1;
            }
            else{
                l=mid+1;
            }
        }
        return l;
        // cout<<pos(nums,7);
        // return mid;
    }
};