class Solution{	
	public:	
		bool uniqueBinaryTree(int a, int b){
			// inorder + preorder
             if ((a == 1 && b == 2) || (a == 2 && b == 1))
                return true;

            // inorder + postorder
            if ((a == 2 && b == 3) || (a == 3 && b == 2))
                return true;

    return false;
		}
};