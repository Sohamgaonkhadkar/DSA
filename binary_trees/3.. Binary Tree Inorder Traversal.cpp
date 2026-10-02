class Solution {
public:
    void inorder(TreeNode* root, vector<int>& ans) {

        if(root == NULL) {
            return;
        }

        inorder(root->left, ans);

        ans.push_back(root->val);

        inorder(root->right, ans);
    }
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> ans;

        inorder(root, ans);

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