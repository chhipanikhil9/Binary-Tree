// 1. if root is one of them or root return root;
// 2. find recursively in the left subtree and right subtree if one of them are null return other else return root;

TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
    if(root==NULL || root==p || root== q) return root;
    TreeNode *l = lowestCommonAncestor(root->left,p,q);
    TreeNode *r = lowestCommonAncestor(root->right,p,q);
    if(l==NULL) return r;
    else if(r==NULL) return l;
    else return root;
}
