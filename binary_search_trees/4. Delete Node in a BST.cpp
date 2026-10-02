class Solution {
public:

    TreeNode* findMin(TreeNode* root) {

        while(root->left != NULL)
            root = root->left;

        return root;
    }

    TreeNode* deleteNode(TreeNode* root, int key) {

        if(root == NULL)
            return NULL;

        // search node
        if(key < root->val) {
            root->left = deleteNode(root->left, key);
        }

        else if(key > root->val) {
            root->right = deleteNode(root->right, key);
        }

        // node found
        else {

            // Case 1: no child
            if(root->left == NULL && root->right == NULL) {
                delete root;
                return NULL;
            }

            // Case 2: one child
            else if(root->left == NULL) {

                TreeNode* temp = root->right;
                delete root;
                return temp;
            }

            else if(root->right == NULL) {

                TreeNode* temp = root->left;
                delete root;
                return temp;
            }

            // Case 3: two children
            else {

                TreeNode* successor = findMin(root->right);

                root->val = successor->val;

                root->right =
                    deleteNode(root->right, successor->val);
            }
        }

        return root;
    }
};