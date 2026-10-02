class Solution {
public:
    TreeNode* searchBST(TreeNode* root, int val) {

        TreeNode* curr = root;

        while(curr != NULL) {

            if(curr->val == val) {
                return curr;
            }
            
            else if(val < curr->val) {
                curr = curr->left;
            }

            else {
                curr = curr->right;
            }
        }

        return NULL;
    }
};