class Solution {
public:

    vector<int> predecessorSuccessor(TreeNode* root,
                                     int key) {

        TreeNode* pred = NULL;
        TreeNode* succ = NULL;

        TreeNode* curr = root;

        while(curr) {

            if(curr->val < key) {
                pred = curr;
                curr = curr->right;
            }

            else if(curr->val > key) {
                succ = curr;
                curr = curr->left;
            }

            else {

                // predecessor
                TreeNode* temp = curr->left;

                while(temp) {
                    pred = temp;
                    temp = temp->right;
                }

                // successor
                temp = curr->right;

                while(temp) {
                    succ = temp;
                    temp = temp->left;
                }

                break;
            }
        }

        return {
            pred ? pred->val : -1,
            succ ? succ->val : -1
        };
    }
};