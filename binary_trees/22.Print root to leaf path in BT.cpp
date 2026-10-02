class Solution {
public:

    void solve(TreeNode* root,
               vector<int>& path,
               vector<vector<int>>& ans) {

        if(root == NULL) {
            return;
        }

        // add current node
        path.push_back(root->val);

        // leaf node
        if(root->left == NULL && root->right == NULL) {
            ans.push_back(path);
        }

        solve(root->left, path, ans);
        solve(root->right, path, ans);

        // backtracking
        path.pop_back();
    }

    vector<vector<int>> allRootToLeaf(TreeNode* root) {

        vector<vector<int>> ans;
        vector<int> path;

        solve(root, path, ans);

        return ans;
    }
};