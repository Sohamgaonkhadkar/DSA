class Solution {
public:

    int findKthSmallest(vector<int>& nums, int k) {

        priority_queue<int> maxHeap;

        for(int num : nums) {

            maxHeap.push(num);

            // Keep only k elements
            if(maxHeap.size() > k) {
                maxHeap.pop();
            }
        }

        return maxHeap.top();
    }
};