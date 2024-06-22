
// Just follow the alog that you know
TreeNode* build(vector<int>& pre, vector<int>& in,int i,int j,int &k){
    if(i>j){
        return NULL;
    }
    int ind = i;
    while(pre[k]!=in[ind]){
        ind++;
    }
    TreeNode *root = new TreeNode(pre[k++]);
    root->left = build(pre,in,i,ind-1,k);
    root->right = build(pre,in,ind+1,j,k);
    return root;
}
TreeNode* buildTree(vector<int>& pre, vector<int>& in) {
    int n = pre.size();
    int k = 0;
    TreeNode* root = build(pre,in,0,n-1,k);
    return root;
}
