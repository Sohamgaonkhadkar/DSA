/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    void dfs (TreeNode* root, vector<vector<int>>& ans ,vector<int>temp,int sum, int targetSum){
        if(root == nullptr) return ;
        temp.push_back(root->val);
        if (root->left == nullptr && root->right == nullptr){
            if(sum==targetSum) ans.push_back(temp);
            return;
        }
        if(root->left){dfs(root->left,ans,temp,sum+root->left->val,targetSum);}
        
        if(root->right){dfs(root->right,ans,temp,sum+root->right->val,targetSum);}
    }
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>> ans;
        vector<int>temp;
        if(root==nullptr) return ans;
        int sum = root->val;
        dfs(root,ans,temp,sum,targetSum);
        return ans;
    }
};
//-2
class Solution {
public:
    void dfs(TreeNode* root, vector<vector<int>>& ans,
             vector<int>& temp, int sum, int targetSum) {
        if (root == nullptr) return;

        temp.push_back(root->val);
        sum += root->val;

        if (root->left == nullptr && root->right == nullptr) {
            if (sum == targetSum)
                ans.push_back(temp);

            temp.pop_back();
            return;
        }

        dfs(root->left, ans, temp, sum, targetSum);
        dfs(root->right, ans, temp, sum, targetSum);

        temp.pop_back();
    }

    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>> ans;
        vector<int> temp;

        dfs(root, ans, temp, 0, targetSum);

        return ans;
    }
};