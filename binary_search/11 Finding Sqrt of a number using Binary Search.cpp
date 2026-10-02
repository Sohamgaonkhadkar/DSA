class Solution {
public:
    int floorSqrt(int n)  {
      int low=0, high=n;
      while(low<=high){
        mid=(low+high)/2;
        if((mid*mid)<=n){
            ans=mid;
            low=mid+1;
        }
        else{
            high = mid-1;
        } 
      }
      return ans;
    }
};