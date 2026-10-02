class Solution {
public:
    unordered_map<string, int> mp;
    vector<TreeNode*> ans;

    string dfs(TreeNode* root) {
        if (!root)
            return "#";

        string s = to_string(root->val) + "," +
                   dfs(root->left) + "," +
                   dfs(root->right);

        mp[s]++;

        if (mp[s] == 2)
            ans.push_back(root);

        return s;
    }

    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
        dfs(root);
        return ans;
    }
};