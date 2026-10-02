class Solution{
	public:
	int perfectSum(vector<int>&arr, int K){
        int n =arr.size();
		vector<int> prev(K+1,0);
		vector<int> curr(K+1,0);
		if(arr[0] == 0)
            prev[0] = 2;
        else
            prev[0] = 1;
		if(arr[0] != 0 && arr[0]<=K)
		    prev[arr[0]]=1;
		for(int i=1;i<n;i++){
		    
		    for(int t=0;t<=K;t++){
		        int notTake=prev[t];
		        int take=0;
		        if(arr[i]<=t)
		            take=prev[t-arr[i]];
		        curr[t]=(take+notTake)%1000000007;
		    }
		    prev=curr;
		}
		return prev[K];
	}
};