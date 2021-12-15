vector<vector<int>> res;
void zigZag(Node* root){
    if(root == NULL) return;
    queue<Node*>q;
    q.push(root);
    bool flag = true;
    while(!q.empty()){
        int n = q.size();
        vector<int> t(n);
        for(int i = 0; i<n; i++){
            Node* temp = q.front();
            q.pop();
            int ind = (flag == true) ? i : (n-i-1);
            t[ind] = temp->data;
            if(temp->left != NULL) q.push(temp->left);
            if(temp->right != NULL) q.push(temp->right);
        }
        flag = !flag;
        res.push_back(t);
    }
}
