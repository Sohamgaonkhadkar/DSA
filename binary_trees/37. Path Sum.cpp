class Solution {
public:
    bool dfs(TreeNode* root, int ans,int targetsum ){
        if (root == nullptr) return false;

        if (root->left == nullptr && root->right == nullptr)
            return ans == targetsum;
         
        if(root->left && dfs(root->left,ans + root->left->val, targetsum)){
            return true;
        }
            
        if(root->right && dfs(root->right,ans + root->right->val, targetsum)){
            return true;
        }
        return false;
    }
    bool hasPathSum(TreeNode* root, int targetSum) {
        if(root == nullptr) return false;
        return dfs(root, root->val, targetSum);
    }
};