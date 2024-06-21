// Two approaches: 
// 1. 
// Time: O(N) 
// space: O(1) except the recursive stack(O(logN))
// Do the post order traversal so that we can get the height in bottom-up manner and we don't have to calculate the height again and again. and just one extra line take the max
// Of global diameter and (l+r) which is for every node.
int height(TreeNode *root, int &d){
    if(root==NULL) return 0;
    int l = height(root->left,d);
    int r = height(root->right,d);
    d = max(d,l+r);
    return 1+max(l,r);
}
int diameterOfBinaryTree(TreeNode* root) {
    if(root==NULL) return 0;
    int d = 0;
    height(root,d);
    return d;
}

// 2. 
// Time: O(N*N) 
// space: O(1) except the recursive stack(O(logN))
// Take every node as a curve node and take its right and left subtree height
int height(TreeNode *root){
    if(root==NULL) return 0;
    int l = height(root->left);
    int r = height(root->right);
    return 1+max(l,r);
}
int diameterOfBinaryTree(TreeNode* root) {
    if(root==NULL) return 0;
    int l = height(root->left);
    int r = height(root->right);
    return max({l+r,diameterOfBinaryTree(root->left),diameterOfBinaryTree(root->right)});
}
