class Solution {
public:

    int diameter = 0;

    int height(TreeNode* root) {

        if(root == NULL)
            return 0;

        int left = height(root->left);
        int right = height(root->right);

        // calculate diameter at current node
        diameter = max(diameter, left + right);

        // return height
        return 1 + max(left, right);
    }

    int diameterOfBinaryTree(TreeNode* root) {

        height(root);

        return diameter;
    }
};