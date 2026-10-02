class Solution {
public:

    vector<vector<int>> treeTraversal(TreeNode* root) {

        vector<int> pre, in, post;

        stack<pair<TreeNode*, int>> st;

        st.push({root, 1});

        while(!st.empty()) {

            auto it = st.top();
            st.pop();

            TreeNode* node = it.first;
            int state = it.second;

            // PREORDER
            if(state == 1) {

                pre.push_back(node->val);

                st.push({node, 2});

                if(node->left) {
                    st.push({node->left, 1});
                }
            }

            // INORDER
            else if(state == 2) {

                in.push_back(node->val);

                st.push({node, 3});

                if(node->right) {
                    st.push({node->right, 1});
                }
            }
            // POSTORDER
            else {

                post.push_back(node->val);
            }
        }

        return {pre, in, post};
    }
};
Preorder  : 1 2 4 5 3 6 7
Inorder   : 4 2 5 1 6 3 7
Postorder : 4 5 2 6 7 3 1
        1
       / \
      2   3
     / \ / \
    4  5 6  7