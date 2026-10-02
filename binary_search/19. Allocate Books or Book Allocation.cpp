class Solution {
public:
    int fun(vector<int>nums,int pages){
        int start=1,pagesStudent=0;
        for(int i=0;i<nums.size();i++){
            
            if(pagesStudent+nums[i]<=pages){
                
                pagesStudent+=nums[i];
            }
            else{
                start++;
                pagesStudent=nums[i];
            }
        }
        return start;
    }

    int findPages(vector<int> &nums, int m)  {
        int sum=0,maxi=0;
        for(int i=0;i<nums.size();i++){
            sum+=nums[i];
            maxi=max(maxi,nums[i]);
        }
        int low=maxi,high=sum;
        while(low<=high){
            int mid=(low+high)/2;
            int cntstu=fun(nums,mid);
            if(cntstu>m){
                low=mid+1;
            }
            else high=mid-1;
        }
    }
    return low;
};