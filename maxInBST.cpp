
//method1
void maxUtil(Node * root, int &maxx){
    if(root == NULL) return;
    maxx = max(root->data, maxx);
    maxUtil(root->left, maxx);
    maxUtil(root->right, maxx);
}

void maxInBST(Node* root){
    int maxx = INT_MIN;
    if(root == NULL) {
        cout<<"Max element in BST is: "<<maxx;;
    }
    maxUtil(root, maxx);
    cout<<"Max element in BST is: "<< maxx;;
}


//method2
int maxBST(Node* root){
    if(root == NULL){
        return INT_MIN;
    }
    return max(root->data, max(maxBST(root->left), maxBST(root->right)));
}
