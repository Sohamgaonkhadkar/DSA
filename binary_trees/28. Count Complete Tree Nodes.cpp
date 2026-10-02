class Solution {
public:

    int leftHeight(TreeNode* root) {

        int height = 0;

        while (root) {
            height++;
            root = root->left;
        }

        return height;
    }

    int rightHeight(TreeNode* root) {

        int height = 0;

        while (root) {
            height++;
            root = root->right;
        }

        return height;
    }

    int countNodes(TreeNode* root) {

        if (root == NULL)
            return 0;

        int lh = leftHeight(root);
        int rh = rightHeight(root);

        // perfect binary tree
        if (lh == rh) {

            return (1 << lh) - 1;
        }

        return 1 + countNodes(root->left)
                 + countNodes(root->right);
    }
};