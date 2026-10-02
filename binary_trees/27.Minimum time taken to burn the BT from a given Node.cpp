class Solution {
public:

    // Store parent pointers
    void markParents(TreeNode* root,
                     unordered_map<TreeNode*, TreeNode*>& parent_track) {

        queue<TreeNode*> q;
        q.push(root);

        while (!q.empty()) {

            TreeNode* current = q.front();
            q.pop();

            if (current->left) {
                parent_track[current->left] = current;
                q.push(current->left);
            }

            if (current->right) {
                parent_track[current->right] = current;
                q.push(current->right);
            }
        }
    }

    // Find target node
    TreeNode* findNode(TreeNode* root, int start) {

        if (root == NULL)
            return NULL;

        if (root->data == start)
            return root;

        TreeNode* left = findNode(root->left, start);

        if (left)
            return left;

        return findNode(root->right, start);
    }

    int timeToBurnTree(TreeNode* root, int start) {

        unordered_map<TreeNode*, TreeNode*> parent_track;

        // build parent mapping
        markParents(root, parent_track);

        // find starting node
        TreeNode* target = findNode(root, start);

        // BFS
        queue<TreeNode*> q;
        q.push(target);

        unordered_map<TreeNode*, bool> visited;
        visited[target] = true;

        int time = -1;

        while (!q.empty()) {

            int size = q.size();

            time++;

            for (int i = 0; i < size; i++) {

                TreeNode* current = q.front();
                q.pop();

                // left
                if (current->left &&
                    !visited[current->left]) {

                    visited[current->left] = true;
                    q.push(current->left);
                }

                // right
                if (current->right &&
                    !visited[current->right]) {

                    visited[current->right] = true;
                    q.push(current->right);
                }

                // parent
                if (parent_track[current] &&
                    !visited[parent_track[current]]) {

                    visited[parent_track[current]] = true;
                    q.push(parent_track[current]);
                }
            }
        }

        return time;
    }
};