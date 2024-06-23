// 1. Using stack push right first and left second so left will process first and right after that
// time: O(N)
// space: O(LogN)
void flatten(TreeNode* root){
  stack<TreeNode*> st;
  st.push(root);
  while(!st.empty()){
    TreeNode *temp = st.top();
    st.pop();
    if(temp->right) st.push(temp->right);
    if(temp->left) st.push(temp->left);
    if(!st.empty()) temp->right = st.top();
    temp->left = NULL;
  }
}

// 2. (Best) use moris traversal: and attech the left's rightmost to the current's right node and fix the cur to the cur->right;
// space: O(1)
// time: O(N)
void flatten(TreeNode* root) {
  if(root==NULL) return;
  TreeNode *cur = root;
  while(cur){
      if(cur->left){
          TreeNode *temp = cur->left;
          while(temp->right) temp = temp->right;
          temp->right = cur->right;
          cur->right = cur->left;
          cur->left = NULL;
      }
      cur = cur->right;
  }
}
