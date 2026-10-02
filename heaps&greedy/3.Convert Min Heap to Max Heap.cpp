class Solution {
public:

    void heapify(vector<int>& nums, int n, int index) {

        while(true) {

            int left = 2 * index + 1;
            int right = 2 * index + 2;

            int largest = index;

            if(left < n && nums[left] > nums[largest]) {
                largest = left;
            }

            if(right < n && nums[right] > nums[largest]) {
                largest = right;
            }

            if(largest != index) {
                swap(nums[index], nums[largest]);
                index = largest;
            }
            else {
                break;
            }
        }
    }

    vector<int> minToMaxHeap(vector<int> nums) {

        int n = nums.size();

        // Start from last non-leaf node
        for(int i = n/2 - 1; i >= 0; i--) {

            heapify(nums, n, i);
        }

        return nums;
    }
};