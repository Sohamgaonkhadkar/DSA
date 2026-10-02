class BSTIterator {
public:
    vector<int> inorder;
    int idx;

    void dfs(TreeNode* root) {
        if(!root) return;

        dfs(root->left);
        inorder.push_back(root->val);
        dfs(root->right);
    }

    BSTIterator(TreeNode* root) {
        idx = -1;
        dfs(root);
    }

    int next() {
        return inorder[++idx];
    }

    bool hasNext() {
        return idx + 1 < inorder.size();
    }
};

//-2
class BSTIterator {
public:
    stack<TreeNode*> st;

    void pushAllLeft(TreeNode* node) {
        while(node) {
            st.push(node);
            node = node->left;
        }
    }

    BSTIterator(TreeNode* root) {
        pushAllLeft(root);
    }

    int next() {

        TreeNode* node = st.top();
        st.pop();

        pushAllLeft(node->right);

        return node->val;
    }

    bool hasNext() {
        return !st.empty();
    }
};