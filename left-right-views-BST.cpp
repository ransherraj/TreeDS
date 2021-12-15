#include <iostream>
#include <bits/stdc++.h>
using namespace std;
struct Node{
    int data;
    Node *left;
    Node *right;
    Node(int k){
        data = k;
        left = NULL;
        right = NULL;
    }
};
void traverse(Node * root){
    if(root == NULL){
        return;
    }
    
    traverse(root->left);
    cout<<root->data<<" ";
    traverse(root->right);
}

void itrPreorder(Node * root){
    if(root == NULL) return;
    stack<Node*> st1;
    st1.push(root);
    while(!st1.empty()){
        Node* temp = st1.top();
        st1.pop();
        cout<<temp->data<<" ";
        if(temp->right) st1.push(temp->right);
        if(temp->left) st1.push(temp->left);
    }
}

void iterInorder(Node * root){
    if(root == NULL){
        return;
    }
    Node* node  = root;
    stack<Node*>st;
    
    while(true){
        
        if(node != NULL){
            st.push(node);
            node = node->left;
        }
        else{
            if(st.empty()) break;
            node = st.top();
            st.pop();
            cout<<node->data<<" ";
            node = node->right;
        }
    }
    
}

void itrPostorder(Node * root){
    if(root == NULL) return;
    stack<Node*> st1, st2;
    st1.push(root);
    while(!st1.empty()){
        Node* temp = st1.top();
        st1.pop();
        st2.push(temp);
        if(temp->left) st1.push(temp->left);
        if(temp->right) st1.push(temp->right);
        
    }
    while(!st2.empty()){
        cout<<st2.top()->data<<" ";
        st2.pop();
    }
}

void leftView(Node * root){
    
    queue<Node*> q;
    q.push(root);
    while(!q.empty()){
        int n = q.size();
        for(int i = 0; i<n; i++){
            Node*temp = q.front();
            q.pop();
            if(i == 0){
                cout<<temp->data<<" ";
            }
            if(temp->left)q.push(temp->left);
            if(temp->right)q.push(temp->right);
        }
    }
}

int maxlevel = 0;

// void leftView2(Node * root, int level){
    
//     if(root == NULL) return;
//     if( maxlevel < level){
//         cout<<root->data<<" ";
//         maxlevel = level;
//     }
//     leftView2(root->left, level+1);
//     leftView2(root->right, level+1); 
// }

int c = 1;
void leftView2(Node * root, int level){
    
    if(root == NULL) return;
    if( c == level){
        cout<<root->data<<" ";
        c++;
    }
    leftView2(root->left, level+1);
    leftView2(root->right, level+1); 
}

void rightView(Node * root){
    
    queue<Node*> q;
    q.push(root);
    while(!q.empty()){
        int n = q.size();
        for(int i = 0; i<n; i++){
            Node*temp = q.front();
            q.pop();
            if(i == n-1){
                cout<<temp->data<<" ";
            }
            if(temp->left)q.push(temp->left);
            if(temp->right)q.push(temp->right);
        }
    }
}

int cnt = 1;
void rightView2(Node * root, int level){
    if(root == NULL) return;
    if( cnt == level){
        cout<<root->data<<" ";
        cnt++;
    }
    rightView2(root->right, level+1); 
    rightView2(root->left, level+1);
    
}


int main() {
	int n;
	Node *root = new Node(10);
	root->left = new Node(20);
	root->right = new Node(30);
	root->left->left = new Node(40);
	root->left->left->left = new Node(70);
	root->left->left->right = new Node(80);
	root->left->left->right->right = new Node(90);
	root->left->right = new Node(50);
	root->right->right = new Node(60);
	root->right->right->left = new Node(100);
    
    cout<<"Inorder Traversal of BTree: "<<endl;
	traverse(root);
	
	cout<<endl<<"Preorder Traversal of BTree iterative method(stack): "<<endl;
	itrPreorder(root);
	
	cout<<endl<<"Inorder Traversal of BTree iterative method(stack): "<<endl;
	iterInorder(root);
	
	cout<<endl<<"postOrder Traversal of BTree iterative method(stack): "<<endl;
	itrPostorder(root);
	
	cout<<endl<<"Left View of BTree: "<<endl;
	leftView(root);
	
	cout<<endl<<"Left View of BTree method 2: "<<endl;
	leftView2(root, 1);
	
	
	
	cout<<endl<<"Right View of BTree: "<<endl;
	rightView(root);
	
	cout<<endl<<"Right View of BTree method 2: "<<endl;
	rightView2(root, 1);
	
	return 0;
}


/*

Inorder Traversal of BTree: 
70 40 80 90 20 50 10 30 100 60 
Preorder Traversal of BTree iterative method(stack): 
10 20 40 70 80 90 50 30 60 100 
Inorder Traversal of BTree iterative method(stack): 
70 40 80 90 20 50 10 30 100 60 
postOrder Traversal of BTree iterative method(stack): 
70 90 80 40 50 20 100 60 30 10 
Left View of BTree: 
10 20 40 70 90 
Left View of BTree method 2: 
10 20 40 70 90 
Right View of BTree: 
10 30 60 100 90 
Right View of BTree method 2: 
10 30 60 100 90 


*/
