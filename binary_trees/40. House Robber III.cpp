class Solution {
    unordered_map<TreeNode*, int> dp;

    int solve(TreeNode* root) {
        if (root == NULL) return 0;

        if (dp.count(root))
            return dp[root];

        // PICK: Rob current house
        int pick = root->val;

        if (root->left)
            pick += solve(root->left->left)
                  + solve(root->left->right);

        if (root->right)
            pick += solve(root->right->left)
                  + solve(root->right->right);

        // NOT PICK: Skip current house
        int notPick = solve(root->left)
                    + solve(root->right);

        return dp[root] = max(pick, notPick);
    }

public:
    int rob(TreeNode* root) {
        dp.clear();
        return solve(root);
    }
};