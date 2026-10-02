class Solution {
public:

    bool search(TreeNode* root, TreeNode* curr, int target) {
        if(root == NULL) return false;

        if(root->val == target) {
            return root != curr;  // must be a different node
        }

        if(target < root->val) {
            return search(root->left, curr, target);
        }

        return search(root->right, curr, target);
    }

    bool find(TreeNode* root, TreeNode* curr, int k) {
        if(curr == NULL) return false;

        int target = k - curr->val;

        if(search(root, curr, target))
            return true;

        return find(root, curr->left, k) ||
               find(root, curr->right, k);
    }

    bool findTarget(TreeNode* root, int k) {
        return find(root, root, k);
    }
};
//-2
class Solution {
public:
    unordered_set<int> st;

    bool dfs(TreeNode* root, int k) {
        if(root == NULL) return false;

        if(st.count(k - root->val))
            return true;

        st.insert(root->val);

        return dfs(root->left, k) ||
               dfs(root->right, k);
    }

    bool findTarget(TreeNode* root, int k) {
        return dfs(root, k);
    }
};