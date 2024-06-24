// time: O(3*N) // for finding the target and for 2 times BFS
// space: O(2*N) // parent + vis
class Solution {
  public:
    Node *ans;
    void find(Node* root, int target){
        if(root==NULL) return;
        if(root->data==target) {
            ans = root;
            return;
        }
        find(root->left,target);
        find(root->right,target);
    }
    int minTime(Node* root, int target) 
    {
        // Your code goes here
        unordered_map<Node*,Node*> parent;
        queue<Node*> q;
        q.push(root);
        while(!q.empty()){
            int m = q.size();
            for(int i=0;i<m;i++){
                Node *temp = q.front();
                q.pop();
                if(temp->left){
                    q.push(temp->left);
                    parent[temp->left] = temp;
                }
                if(temp->right){
                    q.push(temp->right);
                    parent[temp->right] = temp;
                }
            }
        }
        unordered_map<Node*,bool> vis;
        q = queue<Node*>();
        ans = NULL;
        find(root,target);
        q.push(ans);
        vis[ans] = 1;
        int lvl = 0;
        while(!q.empty()){
            int m = q.size();
            int f = 0;
            for(int i=0;i<m;i++){
                Node* cur = q.front();
                q.pop();
                if(cur->left and vis.find(cur->left)==vis.end()){
                    q.push(cur->left);
                    vis[cur->left] = 1;
                    f = 1;
                }
                if(cur->right and vis.find(cur->right)==vis.end()){
                    q.push(cur->right);
                    vis[cur->right] = 1;
                    f = 1;
                }
                if(parent.find(cur)!=parent.end() and vis.find(parent[cur])==vis.end()){
                    vis[parent[cur]] = 1;
                    q.push(parent[cur]);
                    f = 1;
                }
            }
            if(f)
                lvl++;
        }
        return lvl;
    }
};
