class Solution{	
	public:
		vector<int> floorCeilOfBST(TreeNode* root,int key){
        int floor = -1, ceil = -1;

        TreeNode* curr = root;

        while(curr != NULL) {

            if(curr->val == key) {
                floor = curr->val;
                ceil = curr->val;
                break;
            }

            else if(key < curr->val) {
                ceil = curr->val;
                curr = curr->left;
            }

            else {
                floor = curr->val;
                curr = curr->right;
            }
        }

        return {floor, ceil};
		}
};