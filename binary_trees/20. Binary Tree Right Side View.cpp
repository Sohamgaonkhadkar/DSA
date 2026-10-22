// APPROACH 1: DFS (Root -> Right -> Left)

class Solution {
public:
    void recursion(TreeNode* root, int level, vector<int>& res) {
        if (root == NULL)
            return;

        // First node visited at this level is the rightmost node
        if (res.size() == level)
            res.push_back(root->val);

        // Visit right subtree first
        recursion(root->right, level + 1, res);

        // Then visit left subtree
        recursion(root->left, level + 1, res);
    }

    vector<int> rightSideView(TreeNode* root) {
        vector<int> res;

        recursion(root, 0, res);

        return res;
    }
};

// APPROACH 2: BFS (Level Order Traversal)

class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
        vector<int> res;

        if (root == NULL)
            return res;

        queue<TreeNode*> q;
        q.push(root);

        while (!q.empty()) {
            int n = q.size();  // Number of nodes at this level

            for (int i = 0; i < n; i++) {
                TreeNode* node = q.front();
                q.pop();

                // First node processed at this level is rightmost
                if (i == 0)
                    res.push_back(node->val);

                // Push right child first
                if (node->right)
                    q.push(node->right);

                // Push left child second
                if (node->left)
                    q.push(node->left);
            }
        }

        return res;
    }
};