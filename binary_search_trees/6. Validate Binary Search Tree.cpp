class Solution {
public:
    bool isValidBST(TreeNode* root) {
        return check(root, LLONG_MIN, LLONG_MAX);
    }

    bool check(TreeNode* root, long long minVal, long long maxVal) {
        if (root == NULL) return true;

        if (root->val <= minVal || root->val >= maxVal)
            return false;

        return check(root->left, minVal, root->val) &&
               check(root->right, root->val, maxVal);
    }
};

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
    bool isValidBST(TreeNode* root) {

        vector<int> ans;
        inorder(root, ans);
        for(int i = 1; i < ans.size(); i++) {
            if(ans[i] <= ans[i-1]) {
                return false;
            }
        }
        return true;
    }
};

//-2
class Solution {
public:

    bool isValidBST(TreeNode* root) {

        TreeNode* curr = root;
        TreeNode* prev = NULL;

        while(curr) {

            // no left subtree
            if(curr->left == NULL) {

                if(prev && curr->val <= prev->val) {
                    return false;
                }

                prev = curr;

                curr = curr->right;
            }
            else {

                TreeNode* pred = curr->left;

                // find inorder predecessor
                while(pred->right && pred->right != curr) {
                    pred = pred->right;
                }

                // first visit
                if(pred->right == NULL) {

                    pred->right = curr;

                    curr = curr->left;
                }
                else {

                    // VERY IMPORTANT
                    pred->right = NULL;

                    if(prev && curr->val <= prev->val) {
                        return false;
                    }

                    prev = curr;

                    curr = curr->right;
                }
            }
        }

        return true;
    }
};