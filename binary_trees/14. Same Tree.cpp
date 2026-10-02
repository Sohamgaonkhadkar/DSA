class Solution {
public:
    bool check(TreeNode* p, TreeNode* q) {

        // both null
        if(p == NULL && q == NULL) {
            return true;
        }

        // one of them is null
        if(p == NULL || q == NULL) {
            return false;
        }

        // values not equal
        if(p->val != q->val) {
            return false;
        }

        // check left and right subtrees
        return check(p->left, q->left) && check(p->right, q->right);
    }
    bool isSameTree(TreeNode* p, TreeNode* q) {
        return check(p, q);
    }
};