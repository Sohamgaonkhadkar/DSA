class Solution {
public:
    int fun(vector<int>nums,int pages){
        int start=1,largestSum=0;
        for(int i=0;i<nums.size();i++){
            
            if(largestSum+nums[i]<=pages){
                
                largestSum+=nums[i];
            }
            else{
                start++;
                largestSum=nums[i];
            }
        }
        return start;
    }
    int splitArray(vector<int>& nums, int m) {
         int sum=0,maxi=0;
        for(int i=0;i<nums.size();i++){
            sum+=nums[i];
            maxi=max(maxi,nums[i]);
        }
        int low=maxi,high=sum;
        while(low<=high){
            int mid=(low+high)/2;
            int cnt=fun(nums,mid);
            if(cnt>m){
                low=mid+1;
            }
            else high=mid-1;
        }
        return low;
    }
    
    
};