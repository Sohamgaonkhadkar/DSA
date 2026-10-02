class Solution {
public:
    void postorder(TreeNode* root, vector<int>& ans) {

        if(root == NULL) {
            return;
        }

        postorder(root->left, ans);

        postorder(root->right, ans);

        ans.push_back(root->val);
    }
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> ans;

        postorder(root, ans);

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