// same as pre,in to BS
// just change two things;
// 1. change the order from left->right to right->left
// 2. start from n-1 instead of 0 that's all
TreeNode* build(vector<int>& post, vector<int>& in,int i,int j,int &k){
  if(i>j){
      return NULL;
  }
  int ind = i;
  while(post[k]!=in[ind]){
      ind++;
  }
  TreeNode *root = new TreeNode(post[k--]);
  root->right = build(post,in,ind+1,j,k);
  root->left = build(post,in,i,ind-1,k);
  return root;
}
TreeNode* buildTree(vector<int>& in, vector<int>& post) {
  int n = post.size();
  int k = n-1;
  TreeNode* root = build(post,in,0,n-1,k);
  return root;
}
