void BSTsize(Node* root, int &count){
    if(root==NULL)return;
    count++;
    BSTsize(root->left, count);
    BSTsize(root->right, count);
}

int BSTsize2(Node* root){
    if(root==NULL)return 0;
    return 1 + BSTsize2(root->left) + BSTsize2(root->right);
}
