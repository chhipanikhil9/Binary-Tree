// think like a number line and we will access colum wise from above to below so the 
// values will be overriden so use the lavel order traversal with the number line and map
// so at the end map will only contain the bottom view ele accosiated with the each number on number line.
vector <int> bottomView(Node *root) {
    map<int,int> mp;
    queue<pair<Node*,int>> q;
    q.push({root,0});
    while(!q.empty()){
        int m = q.size();
        for(int i=0;i<m;i++){
            Node *cur = q.front().first;
            int val = q.front().second;
            q.pop();
            mp[val] = cur->data;
            if(cur->left){
                q.push({cur->left,val-1});
            }
            if(cur->right){
                q.push({cur->right,val+1});
            }
        }
    }
    vector<int> ans;
    for(auto x:mp){
        ans.push_back(x.second);
    }
    return ans;
}
