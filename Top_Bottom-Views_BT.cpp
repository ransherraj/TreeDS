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

void topView(Node* root, vector<int >&ans){
    if(root == NULL)return;
    map<int, int>mp;
    queue<pair<Node*, int>>q;
    q.push({root, 0});
    while(!q.empty()){
        auto it = q.front();
        q.pop();
        int l = it.second;
        Node* temp = it.first;
        if(mp.find(l) == mp.end()) mp[l] = temp->data;
        if(temp->left) q.push({temp->left, l-1});
        if(temp->right) q.push({temp->right, l+1});
    }
    for(auto x : mp){
        ans.push_back(x.second);
    }
}

void bottomView(Node* root, vector<int >&ans2){
    if(root == NULL)return;
    map<int, int>mp;
    queue<pair<Node*, int>>q;
    q.push({root, 0});
    while(!q.empty()){
        auto it = q.front();
        q.pop();
        int l = it.second;
        Node* temp = it.first;
        mp[l] = temp->data;
        if(temp->left) q.push({temp->left, l-1});
        if(temp->right) q.push({temp->right, l+1});
    }
    for(auto x : mp){
        ans2.push_back(x.second);
    }
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
    
    cout<< "Top View of BT : "<<endl;
    vector<int >ans;
    topView(root, ans);
    for(int i = 0; i<ans.size(); i++){
        cout<<ans[i]<<" ";
    }
    
    cout<<endl<<endl<< "Bottom View of BT : "<<endl;
    vector<int >ans2;
    bottomView(root, ans2);
    for(int i = 0; i<ans2.size(); i++){
        cout<<ans2[i]<<" ";
    }
   
	return 0;
}

/*

Top View of BT : 
70 40 20 10 30 60 

Bottom View of BT : 
70 40 80 90 100 60 

*/
