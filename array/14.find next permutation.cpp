class Solution {
public:
    vector<int> nextGreaterPermutation(vector<int>& A) {
        int n = A.size();
        int ind = -1;

        // Step 1: find the break point
        for (int i = n - 2; i >= 0; i--) {
            if (A[i] < A[i + 1]) {
                ind = i;
                break;
            }
        }

        // Step 2: if no break point, reverse entire array
        if (ind == -1) {
            reverse(A.begin(), A.end());
            return A;
        }

        // Step 3: find next greater element and swap
        for (int i = n - 1; i > ind; i--) {
            if (A[i] > A[ind]) {
                swap(A[i], A[ind]);
                break;
            }
        }

        // Step 4: reverse the suffix
        reverse(A.begin() + ind + 1, A.end());

        return A;
    }
};
