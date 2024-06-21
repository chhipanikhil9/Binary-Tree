// Time: O(N) 
// Space: O(N)
// do the post-order traversal so that we don't need to calculate the heights again and again.
int height(TreeNode* root,bool &f){
    if(root==NULL) return 0;
    int l = height(root->left,f);
    int r = height(root->right,f);
    if(abs(r-l)>1){
        f = 0;
        return 0;
    }
    return 1+max(l,r);
}

bool isBalanced(TreeNode* root) {
    if(root==NULL) return true;
    bool f = 1;
    height(root,f);
    return f;
}

