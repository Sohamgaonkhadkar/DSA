/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:

    // Build parent mapping
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

    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {

        // child -> parent
        unordered_map<TreeNode*, TreeNode*> parent_track;

        markParents(root, parent_track);

        // BFS from target
        queue<TreeNode*> q;
        q.push(target);

        unordered_map<TreeNode*, bool> visited;
        visited[target] = true;

        int curr_level = 0;

        while (!q.empty()) {

            int size = q.size();

            // reached distance k
            if (curr_level++ == k)
                break;

            for (int i = 0; i < size; i++) {

                TreeNode* current = q.front();
                q.pop();

                // left child
                if (current->left && !visited[current->left]) {

                    visited[current->left] = true;
                    q.push(current->left);
                }

                // right child
                if (current->right && !visited[current->right]) {

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

        vector<int> result;

        while (!q.empty()) {

            TreeNode* current = q.front();
            q.pop();

            result.push_back(current->val);
        }

        return result;
    }
};