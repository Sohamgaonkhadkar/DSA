class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {

        int n = nums1.size();
        int m = nums2.size();

        vector<int> nums(n + m);

        int i = n - 1;
        int j = m - 1;
        int k = n + m - 1;

        // Merge from the back
        while (i >= 0 && j >= 0) {
            if (nums1[i] > nums2[j]) {
                nums[k] = nums1[i];
                i--;
            } else {
                nums[k] = nums2[j];
                j--;
            }
            k--;
        }

        while (i >= 0) {
            nums[k] = nums1[i];
            i--;
            k--;
        }

        while (j >= 0) {
            nums[k] = nums2[j];
            j--;
            k--;
        }

        int total = n + m;

        if (total % 2 == 1) {
            return nums[total / 2];
        } 
        else {
            int mid1 = total / 2;
            int mid2 = mid1 - 1;

            return (nums[mid1] + nums[mid2]) / 2.0;
        }
    }
};
//-2
class Solution {
public:
    double findMedianSortedArrays(vector<int>& a, vector<int>& b) {
        
        int n1 = a.size();
        int n2 = b.size();
        
        int n = n1 + n2;
        int ind2 = n/2;
        int ind1 = ind2 - 1;
        
        int cnt = 0;
        int i = 0, j = 0;
        
        int ind1el = -1, ind2el = -1;
        
        while(i < n1 && j < n2){
            
            if(a[i] < b[j]){
                
                if(cnt == ind1) ind1el = a[i];
                if(cnt == ind2) ind2el = a[i];
                
                cnt++;
                i++;
            }
            else{
                
                if(cnt == ind1) ind1el = b[j];
                if(cnt == ind2) ind2el = b[j];
                
                cnt++;
                j++;
            }
        }
        
        while(i < n1){
            
            if(cnt == ind1) ind1el = a[i];
            if(cnt == ind2) ind2el = a[i];
            
            cnt++;
            i++;
        }
        
        while(j < n2){
            
            if(cnt == ind1) ind1el = b[j];
            if(cnt == ind2) ind2el = b[j];
            
            cnt++;
            j++;
        }
        
        if(n % 2 == 1)
            return ind2el;
        
        return (ind1el + ind2el) / 2.0;
    }
};

//-3
double median(vector<int>& a, vector<int>& b) {
    int n1 = a.size();
    int n2 = b.size();

    // ensure a is smaller array
    if(n1 > n2) return median(b, a);

    int low = 0, high = n1;
    int left = (n1 + n2 + 1) / 2;
    int n = n1 + n2;

    while(low <= high) {

        int mid1 = (low + high) / 2;
        int mid2 = left - mid1;

        int l1 = INT_MIN, l2 = INT_MIN;
        int r1 = INT_MAX, r2 = INT_MAX;

        if(mid1 < n1) r1 = a[mid1];
        if(mid2 < n2) r2 = b[mid2];

        if(mid1 - 1 >= 0) l1 = a[mid1 - 1];
        if(mid2 - 1 >= 0) l2 = b[mid2 - 1];

        if(l1 <= r2 && l2 <= r1) {

            if(n % 2 == 1)
                return max(l1, l2);

            return (max(l1,l2) + min(r1,r2)) / 2.0;
        }
        else if(l1 > r2)
            high = mid1 - 1;
        else
            low = mid1 + 1;
    }

    return 0;
}