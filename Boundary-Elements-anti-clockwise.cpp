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


bool isLeave(Node* root){
    if(root == NULL) return false;
    if(root->left == NULL && root->right == NULL) return true;
    else return false;
}

vector<int>res;

void addLeftBoundary(Node* root){
    if(!root)return;
    Node* temp = root->left;
    while(temp!=NULL){
        if(!isLeave(temp))res.push_back(temp->data);
        if(temp->left){
            temp = temp->left;
        }
        else{
            temp = temp->right;
        }
    }
}

void addLeaves(Node* root){
    if(root == NULL) return;
    if(isLeave(root)) res.push_back(root->data);
    addLeaves(root->left);
    addLeaves(root->right);
}

void addRightBoundary(Node* root){
    if(!root)return;
    Node* temp = root->right;
    vector<int> t;
    while(temp!=NULL){
        if(!isLeave(temp)) t.push_back(temp->data);
        if(temp->right){
            temp = temp->right;
        }
        else{
            temp = temp->left;
        }
    }
    for(int i = t.size()-1; i>=0; i--){
        res.push_back(t[i]);
    }
}

void boundaryElements(Node* root){
    if(!root) return;
    if(!isLeave(root)) res.push_back(root->data);
    addLeftBoundary(root);
    addLeaves(root);
    addRightBoundary(root);
    
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
    
    cout<< "Boundary Elements Anticlock- wise : "<<endl;
    boundaryElements(root);
    for(auto y : res){
        cout<<y<<" ";
    }
   
	return 0;
}

/*

Boundary Elements Anticlock- wise : 
10 20 40 70 90 50 100 60 30 


*/
