class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int n=nums.size();
        int idx=0;
        for(int i=0;i<n;i++){
            if(nums[i]!=0){
                nums[idx++]=nums[i];

            }            
        }
        while (idx < n) {
            nums[idx++] = 0;
        }
        
    }
};

//2
vector<int> moveZeros(int n, vector<int> a) {

    int j = -1;

    // find first zero
    for (int i = 0; i < n; i++) {
        if (a[i] == 0) {
            j = i;
            break;
        }
    }

    // no zero present
    if (j == -1) return a;

    // move non-zero elements forward
    for (int i = j + 1; i < n; i++) {
        if (a[i] != 0) {
            swap(a[i], a[j]);
            j++;
        }
    }

    return a;
}
