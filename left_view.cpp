// Can be done using level order traversal just take the first ele from each level
// Right view is also same just make it right left node

void traverse(Node* root,int lvl,vector<int> &ans){
    if(root==NULL) return;
    if(lvl==ans.size())
        ans.push_back(root->data);
    traverse(root->left,lvl+1,ans);
    traverse(root->right,lvl+1,ans);
}
vector<int> leftView(Node *root)
{
   // Your code here
   vector<int> ans;
   traverse(root,0,ans);
   return ans;
}
