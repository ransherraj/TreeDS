#include <iostream>
#include <bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    Node* left;
    Node* right;
    Node(int k){
        data = k;
        left = nullptr;
        right = nullptr;
    }
};

void inorder(Node * root){
    if(root == NULL){
        return;
    }
    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
    
}

void preorder(Node * root){
    if(root == NULL){
        return;
    }
    cout<<root->data<<" ";
    preorder(root->left);
    preorder(root->right);
    
}

void postorder(Node * root){
    if(root == NULL){
        return;
    }
    postorder(root->left);
    postorder(root->right);
    cout<<root->data<<" ";
    
}

void kthHeightElements(Node * root, int k){
    if(root == NULL){
        return;
    }
    if(k == 0){
        cout<< root->data <<" ";
    }
    else{
        kthHeightElements(root->left, k-1);
        kthHeightElements(root->right, k-1);
    }
    
}

void levelorder(Node * root){
    if(root == NULL) return;
    queue<Node*> q;
    q.push(root);
    
    while(!q.empty()){
        Node* temp = q.front();
        cout<<temp->data<<" ";
        q.pop();
        if(temp->left != NULL) q.push(temp->left);
        if(temp->right != NULL) q.push(temp->right);
    }
}

int height(Node * root){
    if(root == NULL){
        return 0;
    }
    return  1 + max( height(root->left), height(root->right) );
    
}
int main() {
	
	Node* root = new Node(10);
	root->left = new Node(20);
	root->right = new Node(30);
	root->right->left = new Node(40);
	root->right->right = new Node(50);
	
	cout<<"Inorder traversal of tree: ";
	inorder(root);
	cout<<endl;
	
	cout<<"preorder traversal of tree: ";
	preorder(root);
	cout<<endl;
	
	cout<<"postorder traversal of tree: ";
	postorder(root);
	cout<<endl;
	
	cout<<"Height of tree: ";
	cout<<height(root);
	cout<<endl;
	
	cout<<"kth Height elements: ";
	kthHeightElements(root, 2);
	cout<<endl;
	
	cout<<"Level order elements: ";
	levelorder(root);
	cout<<endl;
}


/*
output:

Inorder traversal of tree: 20 10 40 30 50 
preorder traversal of tree: 10 20 30 40 50 
postorder traversal of tree: 20 40 50 30 10 
Height of tree: 3
kth Height elements: 40 50 
Level order elements: 10 
20 
30 
40 
50 


*/
