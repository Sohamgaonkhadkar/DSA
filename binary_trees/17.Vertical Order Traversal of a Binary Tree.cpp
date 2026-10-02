class Solution {
public:

    vector<vector<int>> verticalTraversal(TreeNode* root) {

        // vertical -> level -> multiset
        map<int, map<int, multiset<int>>> nodes;

        // node, vertical, level
        queue<pair<TreeNode*, pair<int,int>>> q;

        q.push({root, {0,0}});

        while(!q.empty()) {

            auto temp = q.front();
            q.pop();

            TreeNode* node = temp.first;

            int vertical = temp.second.first;
            int level = temp.second.second;

            nodes[vertical][level].insert(node->val);

            // left
            if(node->left) {
                q.push({node->left, {vertical-1, level+1}});
            }

            // right
            if(node->right) {
                q.push({node->right, {vertical+1, level+1}});
            }
        }

        vector<vector<int>> ans;

        for(auto p : nodes) {

            vector<int> col;

            for(auto q : p.second) {

                for(auto val : q.second) {
                    col.push_back(val);
                }
            }

            ans.push_back(col);
        }

        return ans;
    }
};