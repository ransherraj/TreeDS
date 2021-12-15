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


void preInPost(Node*root, vector<int> &pre, vector<int> &in, vector<int> &post)
{
    if(root == NULL){
        return;
    }
    stack<pair<Node*, int>> st;
    st.push({root, 1});
    while(!st.empty()){
        auto it = st.top();
        st.pop();
        if(it.second == 1){
            pre.push_back(it.first->data);
            it.second++;
            st.push(it);
            if(it.first->left != NULL) {
                st.push({it.first->left, 1});
            }
        }
        
        else if(it.second == 2){
            in.push_back(it.first->data);
            it.second++;
            st.push(it);
            if(it.first->right != NULL) {
                st.push({it.first->right, 1});
            }
        }
        
        else{
            post.push_back(it.first->data);
        }
    }
}

int main() {
	
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
	
	cout<<"Preorder-Inorder-Postorder:"<<endl;
	vector<int>pre, in, post;
	preInPost(root, pre, in, post);
	
	int n = pre.size();
	cout<<"preorder: ";
	for(int i = 0; i<n; i++){
	    cout<<pre[i]<<" ";
	}
	
	cout<<endl<<"inorder: ";
	for(int i = 0; i<n; i++){
	    cout<<in[i]<<" ";
	}
	
	cout<<endl<<"postorder: ";
	for(int i = 0; i<n; i++){
	    cout<<post[i]<<" ";
	}
	cout<<endl;
	
	return 0;
}

/*
OUTPUT:

Preorder-Inorder-Postorder:
preorder: 10 20 40 70 80 90 50 30 60 100 
inorder: 70 40 80 90 20 50 10 30 100 60 
postorder: 70 90 80 40 50 20 100 60 30 10 


*/
