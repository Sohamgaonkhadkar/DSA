class Solution {
public:
    bool check(TreeNode* left, TreeNode* right) {

        // both null
        if(left == NULL && right == NULL) {
            return true;
        }

        // one of them is null
        if(left == NULL || right == NULL) {
            return false;
        }

        // values not equal
        if(left->val != right->val) {
            return false;
        }

        // check left and right subtrees
        return check(left->left, right->right) && check(left->right, right->left);
    }
    bool isSymmetric(TreeNode* root) {
        if(root == NULL) {
            return true;
        }

        return check(root->left, root->right);
    }
};