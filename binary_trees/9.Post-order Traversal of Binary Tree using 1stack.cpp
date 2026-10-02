class Solution {
public:

    vector<int> postorderTraversal(TreeNode* root) {

        vector<int> postorder;

        stack<TreeNode*> st;

        TreeNode* curr = root;

        while(curr != NULL || !st.empty()) {

            // GO LEFT
            if(curr != NULL) {

                st.push(curr);

                curr = curr->left;
            }

            else {

                TreeNode* temp = st.top()->right;

                // RIGHT CHILD DOES NOT EXIST
                if(temp == NULL) {

                    temp = st.top();
                    st.pop();

                    postorder.push_back(temp->val);

                    // CHECK IF COMING FROM RIGHT
                    while(!st.empty() && temp == st.top()->right) {

                        temp = st.top();
                        st.pop();

                        postorder.push_back(temp->val);
                    }
                }

                // MOVE TO RIGHT SUBTREE
                else {

                    curr = temp;
                }
            }
        }

        return postorder;
    }
};