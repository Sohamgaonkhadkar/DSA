class Solution {
public:
    void dfs(TreeNode* root,int depth, int& ans){
        if(root == nullptr)
            return;
        if(root->left == nullptr && root->right == nullptr){
            ans = min(ans, depth);
            return;
        }
        dfs(root->left, depth + 1, ans);
        dfs(root->right, depth + 1, ans);

    }
    int minDepth(TreeNode* root) {
        if (root == nullptr)
            return 0;
        int ans = INT_MAX;

        dfs(root,1,ans);
        return ans;
    }
};
//-2
class Solution {
public:
    int minDepth(TreeNode* root) {
        if (root == nullptr) return 0;

        queue<pair<TreeNode*, int>> q;
        q.push({root, 1});

        while (!q.empty()) {
            auto [node, depth] = q.front();
            q.pop();

            if (node->left == nullptr && node->right == nullptr)
                return depth;

            if (node->left)
                q.push({node->left, depth + 1});

            if (node->right)
                q.push({node->right, depth + 1});
        }

        return 0;
    }
};