class Solution {
public:

    void preorder(TreeNode* root, vector<int>& ans) {

        if(root == NULL) {
            return;
        }

        ans.push_back(root->val);

        preorder(root->left, ans);

        preorder(root->right, ans);
    }

    vector<int> preorderTraversal(TreeNode* root) {

        vector<int> ans;

        preorder(root, ans);

        return ans;
    }
};
Preorder  : 1 2 4 5 3
Inorder   : 4 2 5 1 3
Postorder : 4 5 2 3 1
        1
       / \
      2   3
     / \
    4   5