class Solution {
public:

    int height(TreeNode* root) {

        // empty tree
        if(root == NULL)
            return 0;

        int left = height(root->left);

        // left subtree already unbalanced
        if(left == -1)
            return -1;

        int right = height(root->right);

        // right subtree already unbalanced
        if(right == -1)
            return -1;

        // current node unbalanced
        if(abs(left - right) > 1)
            return -1;

        // return normal height
        return 1 + max(left, right);
    }

    bool isBalanced(TreeNode* root) {

        return height(root) != -1;
    }
};