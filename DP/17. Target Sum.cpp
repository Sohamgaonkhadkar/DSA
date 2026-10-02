class Solution {
public:
    int findTargetSumWays(vector<int>& arr, int target) {

        int totalSum = accumulate(arr.begin(), arr.end(), 0);

        if(totalSum + target < 0 || (totalSum + target) % 2)
            return 0;

        int req = (totalSum + target) / 2;

        vector<int> prev(req + 1, 0);
        vector<int> curr(req + 1, 0);
        if(arr[0] == 0)
            prev[0] = 2;
        else
            prev[0] = 1;
        if(arr[0] != 0 && arr[0] <= req)
            prev[arr[0]] = 1;
        for(int i = 1; i < arr.size(); i++){
            
            for(int t = 0; t <= req; t++){
		        int notTake=prev[t];
		        int take=0;
		        if(arr[i]<=t)
		            take=prev[t-arr[i]];
		        curr[t]=(take+notTake);
		    }
		    prev=curr;
		}
		return prev[req];
    }
};
