class Info {
public:
    int minNode;
    int maxNode;
    int sum;

    Info(int minNode, int maxNode, int sum) {
        this->minNode = minNode;
        this->maxNode = maxNode;
        this->sum = sum;
    }
};

class Solution {
public:
    int maxSum = 0;

    Info solve(TreeNode* root) {

        // Empty tree is BST
        if(root == NULL) {
            return Info(INT_MAX, INT_MIN, 0);
        }

        auto left = solve(root->left);
        auto right = solve(root->right);

        // Current subtree is BST
        if(left.maxNode < root->val &&
           root->val < right.minNode) {

            int currSum =
                left.sum +
                right.sum +
                root->val;

            maxSum = max(maxSum, currSum);

            return Info(
                min(root->val, left.minNode),
                max(root->val, right.maxNode),
                currSum
            );
        }

        // Not a BST
        return Info(
            INT_MIN,
            INT_MAX,
            max(left.sum, right.sum)
        );
    }

    int maxSumBST(TreeNode* root) {

        solve(root);

        return maxSum;
    }
};
//-2
class NodeValue {
public:
    int minNode, maxNode, maxSize;

    NodeValue(int minNode, int maxNode, int maxSize) {
        this->minNode = minNode;
        this->maxNode = maxNode;
        this->maxSize = maxSize;
    }
};

class Solution {
public:

    NodeValue solve(TreeNode* root) {

        if(root == NULL) {
            return NodeValue(INT_MAX, INT_MIN, 0);
        }

        auto left = solve(root->left);
        auto right = solve(root->right);

        if(left.maxNode < root->val &&
           root->val < right.minNode) {

            return NodeValue(
                min(root->val, left.minNode),
                max(root->val, right.maxNode),
                left.maxSize + right.maxSize + 1
            );
        }

        return NodeValue(
            INT_MIN,
            INT_MAX,
            max(left.maxSize, right.maxSize)
        );
    }

    int largestBSTSubtree(TreeNode* root) {
        return solve(root).maxSize;
    }
};

