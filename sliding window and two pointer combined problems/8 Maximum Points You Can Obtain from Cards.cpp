class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int n= cardPoints.size();
        int maxlen= n-k;
        int sum=0;
        int left=0;
        int right=0;
        for(int i=0;i<n;i++){
            sum+=cardPoints[i];
        }
        
        int currsum=0;
        int minsum=INT_MAX;
        for(int i=0;i<n;i++){
            currsum+=cardPoints[i];
            if(i-left+1>maxlen){
                currsum-=cardPoints[left];
                left++;
            }
            if(i-left+1==maxlen){
                minsum=min(minsum, currsum);
            }
        }
        return sum-minsum;
    }
};

//-2
class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        // we can either only pick from front or back
        // so we pick k elements from the front and one by one shrink one car from the front and add another card from the back 
        int n = cardPoints.size();
        //calculate sum for the first k cards
        int currPoints =0;
        for(int i =0;i<k;i++){
            currPoints += cardPoints[i];
        }
        int l = k-1, r =  n-1;
        int maxPoints =currPoints;

        while(r>l && l >=0){
            // remove one element from front 
            currPoints = currPoints - cardPoints[l];
            l = l-1;
            // add the lcard from the back
            currPoints = currPoints + cardPoints[r];
            r = r-1;
            maxPoints = max(currPoints,maxPoints);
        }
        return maxPoints;
    }
};