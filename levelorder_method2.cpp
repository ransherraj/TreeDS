void levelorderLine2(Node * root){
    if(root == NULL) return;
    queue<Node*> q;
    q.push(root);
    while(!q.empty()){
        int s = q.size();
        for(int i = 0; i<s; i++){
            Node* temp = q.front();
            q.pop();
            cout<<temp->data<<" ";
            if(temp->left != NULL) q.push(temp->left);
            if(temp->right != NULL) q.push(temp->right);
        }
        cout<<endl;
    }
}
