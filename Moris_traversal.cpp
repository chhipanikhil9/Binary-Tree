// Time: O(2*N)
// Space: O(1)
vector<int> inorderTraversal(TreeNode* root) {
    vector<int> ans;
    TreeNode *cur = root;
    while(cur!=NULL){
        // if left is null take the ele and go to right
        if(cur->left==NULL){
            ans.push_back(cur->val);
            cur = cur->right;
        }
        // else you have to do the thread thing
        else{
            // go to the rightest to the left of current
            TreeNode *pre = cur->left;
            while(pre->right and pre->right != cur){
                pre = pre->right;
            }
            // if rightest is not connected through the thread to cur connect it
            // and go to left;
            if(pre->right==NULL){
                pre->right = cur;
                cur = cur->left;
            }
            // otherwise we have already connected it its time to remove back and put the 
            // ele in the ans and go to right
            else{
                pre->right = NULL;
                ans.push_back(cur->val);
                cur = cur->right;
            }
        }
    }
    return ans;
}
