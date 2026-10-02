class Solution {
public:
    void flatten(TreeNode* root) {

        TreeNode* curr = root;

        while(curr != NULL) {

            if(curr->left) {

                // find rightmost node of left subtree
                TreeNode* pred = curr->left;

                while(pred->right) {
                    pred = pred->right;
                }

                // connect old right subtree
                pred->right = curr->right;

                // move left subtree to right
                curr->right = curr->left;

                curr->left = NULL;
            }

            curr = curr->right;
        }
    }
};