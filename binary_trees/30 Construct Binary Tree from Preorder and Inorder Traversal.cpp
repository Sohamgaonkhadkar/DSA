class Solution {
public:

    TreeNode* solve(vector<int>& preorder,
                    int preStart,
                    int preEnd,
                    vector<int>& inorder,
                    int inStart,
                    int inEnd,
                    unordered_map<int,int>& mp) {

        // base case
        if (preStart > preEnd || inStart > inEnd)
            return NULL;

        // root from preorder
        TreeNode* root = new TreeNode(preorder[preStart]);

        // root index in inorder
        int inRoot = mp[root->val];

        // number of nodes in left subtree
        int numsLeft = inRoot - inStart;

        // build left subtree
        root->left = solve(preorder,
                           preStart + 1,
                           preStart + numsLeft,
                           inorder,
                           inStart,
                           inRoot - 1,
                           mp);

        // build right subtree
        root->right = solve(preorder,
                            preStart + numsLeft + 1,
                            preEnd,
                            inorder,
                            inRoot + 1,
                            inEnd,
                            mp);

        return root;
    }

    TreeNode* buildTree(vector<int>& preorder,
                        vector<int>& inorder) {

        unordered_map<int,int> mp;

        // store inorder indexes
        for (int i = 0; i < inorder.size(); i++) {
            mp[inorder[i]] = i;
        }

        return solve(preorder,
                     0,
                     preorder.size() - 1,
                     inorder,
                     0,
                     inorder.size() - 1,
                     mp);
    }
};