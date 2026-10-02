class Solution {
public:

    TreeNode* lowestCommonAncestor(TreeNode* root,
                                   TreeNode* p,
                                   TreeNode* q) {

        // base case
        if(root == NULL) {
            return NULL;
        }

        if(root == p || root == q) {
            return root;
        }

        TreeNode* leftAns =
            lowestCommonAncestor(root->left, p, q);

        TreeNode* rightAns =
            lowestCommonAncestor(root->right, p, q);

        // both sides returned something
        if(leftAns != NULL && rightAns != NULL) {
            return root;
        }

        // only left side
        if(leftAns != NULL) {
            return leftAns;
        }

        // only right side
        return rightAns;
    }
};