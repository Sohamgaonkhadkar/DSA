class Solution {
public:

    vector<int> inorderTraversal(TreeNode* root) {

        vector<int> inorder;

        stack<TreeNode*> st;

        TreeNode* node = root;

        while(true) {

            if(node != NULL) {

                st.push(node);

                node = node->left;
            }

            else {

                if(st.empty()) {
                    break;
                }

                node = st.top();
                st.pop();

                inorder.push_back(node->val);

                node = node->right;
            }
        }

        return inorder;
    }
};
        1
       / \
      2   3
     / \
    4   5
    Inorder : 4 2 5 1 3
    