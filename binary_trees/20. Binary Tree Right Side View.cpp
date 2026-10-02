class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
         vector<int> ans;
        
        if(root == NULL) {
            return ans;
        }
        
        // hd -> node value
        map<int,int> mp;
        
        // node , horizontal distance
        queue<pair<Node*, int>> q;
        
        q.push({root, 0});
        
        while(!q.empty()) {
            
            auto temp = q.front();
            q.pop();
            
            Node* frontNode = temp.first;
            int hd = temp.second;
            
            // first node at this hd
            if(mp.find(hd) == mp.end()) {
                mp[hd] = frontNode->data;
            }

            // right child
            if(frontNode->right) {
                q.push({frontNode->right, hd + 1});
            }

            // left child
            if(frontNode->left) {
                q.push({frontNode->left, hd + 1});
            }
            
            
        }
        
        // map stores sorted by hd
        for(auto i : mp) {
            ans.push_back(i.second);
        }
        
        return ans;
    }
};