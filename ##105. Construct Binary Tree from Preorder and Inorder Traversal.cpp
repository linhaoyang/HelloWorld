
#分治
inorder 用来区分 左右子树  preorder用来鉴定访问顺序


import javafx.util.Pair;
class Solution {
  public Pair<TreeNode, int []> helper(int[] preorder, int[] inorder) {
    if (inorder.length == 0) {
      return new Pair(null, preorder);
    }

    // pick up the first element as a root
    int root_val = preorder[0];
    TreeNode root = new TreeNode(root_val);

    // find index of root in the inorder list
    int index = 0;
    for (; (index < inorder.length) && (inorder[index] != root_val); index++){}
    preorder = Arrays.copyOfRange(preorder, 1, preorder.length);

    // root splits inorder list
    // into left and right subtrees        
    int [] left_inorder = Arrays.copyOfRange(inorder, 0, index);
    int [] right_inorder = index + 1 <= inorder.length ? 
      Arrays.copyOfRange(inorder, index + 1, inorder.length) : new int [0];

    // recursion
    Pair<TreeNode, int []> p = helper(preorder, left_inorder);
    root.left = p.getKey();
    preorder = p.getValue();
    p = helper(preorder, right_inorder);
    root.right = p.getKey();
    preorder = p.getValue();

    return new Pair(root, preorder);
  }

  public TreeNode buildTree(int[] preorder, int[] inorder) {
    Pair<TreeNode, int []> result = helper(preorder, inorder);
    return result.getKey();
  }
}


=======================================================================================================================


TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder) {
    return create(preorder, inorder, 0, preorder.size() - 1, 0, inorder.size() - 1);
}

TreeNode* create(vector<int>& preorder, vector<int>& inorder, int ps, int pe, int is, int ie){
    if(ps > pe){
        return nullptr;
    }
    TreeNode* node = new TreeNode(preorder[ps]);
    int pos;
    for(int i = is; i <= ie; i++){
        if(inorder[i] == node->val){
            pos = i;
            break;
        }
    }
    node->left = create(preorder, inorder, ps + 1, ps + pos - is, is, pos - 1);
                                                        //可替换
    node->right = create(preorder, inorder, pe - ie + pos + 1 or ps + pos - is + 1, pe, pos + 1, ie);
    return node;
}

====================================================================================================
