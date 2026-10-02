vector<int> inorderTraversal(TreeNode* root) {

    vector<int> ans;

    TreeNode* curr = root;

    while(curr != NULL) {

        // no left subtree
        if(curr->left == NULL) {

            ans.push_back(curr->val);

            curr = curr->right;
        }
        else {

            TreeNode* pred = curr->left;

            // find rightmost node
            while(pred->right && pred->right != curr) {
                pred = pred->right;
            }

            // create thread
            if(pred->right == NULL) {

                pred->right = curr;

                curr = curr->left;
            }
            else {

                // remove thread
                pred->right = NULL;

                ans.push_back(curr->val);

                curr = curr->right;
            }
        }
    }

    return ans;
}

vector<int> preorderTraversal(TreeNode* root) {

    vector<int> ans;

    TreeNode* curr = root;

    while(curr != NULL) {

        if(curr->left == NULL) {

            ans.push_back(curr->val);

            curr = curr->right;
        }
        else {

            TreeNode* pred = curr->left;

            while(pred->right && pred->right != curr) {
                pred = pred->right;
            }

            // first time visiting
            if(pred->right == NULL) {

                ans.push_back(curr->val);

                pred->right = curr;

                curr = curr->left;
            }
            else {

                pred->right = NULL;

                curr = curr->right;
            }
        }
    }

    return ans;
}