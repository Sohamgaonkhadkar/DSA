class Solution {
public:
    int idx = 0;

    TreeNode* solve(vector<int>& preorder, int bound) {

        if(idx == preorder.size() ||
           preorder[idx] > bound)
            return NULL;

        TreeNode* root =
            new TreeNode(preorder[idx++]);

        root->left =
            solve(preorder, root->val);

        root->right =
            solve(preorder, bound);

        return root;
    }

    TreeNode* bstFromPreorder(vector<int>& preorder) {

        return solve(preorder, INT_MAX);
    }
};