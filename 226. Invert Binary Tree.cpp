class Solution {
    public TreeNode invertTree(TreeNode root) {
        
        if(root == null) return null;
        
        invertTree(root.left);
        invertTree(root.right);
        
        TreeNode temp = root.left;
        
        root.left = root.right;
        
        root.right = temp;
        
        return root;
        
    }
   
}


=====================================================================================


TreeNode* invertTree(TreeNode* root) {
    std::stack<TreeNode*> stk;
    stk.push(root);
    
    while (!stk.empty()) {
        TreeNode* p = stk.top();
        stk.pop();
        if (p) {
            stk.push(p->left);
            stk.push(p->right);
            std::swap(p->left, p->right);
        }
    }
    return root;
}
