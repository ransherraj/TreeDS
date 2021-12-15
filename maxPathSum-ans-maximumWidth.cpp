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

int maxPathSum(Node* root, int &sum ){
    if(root == NULL){
        return 0;
    }
    int ls = max(0, maxPathSum(root->left, sum));
    int rs = max(0, maxPathSum(root->right, sum));
    sum = max(sum, ls + rs + root->data);
    return root->data + max(ls, rs);
}

int maxSum(Node* root){
    if(root == NULL) return 0;
    int sum = 0;
    maxPathSum(root, sum);
    return sum;
}

int maxWidth(Node* root){
    if(root == NULL) return 0;
    int ans = 0;
    queue<pair<Node*, int>>q;
    q.push({root, 0});
    while(!q.empty()){
        int minn = q.front().second;
        int n = q.size();
        int first, last;
        for(int i = 0; i<n; i++){
            int id = q.front().second - minn;
            Node* temp = q.front().first;
            q.pop();
            if(i == 0) first = id;
            if(i == n-1)last = id;
            if(temp->left){
                q.push({temp->left, id*2 + 1});
            }
            if(temp->right){
                q.push({temp->right, id*2 + 2});
            }
        }
        ans = max(ans, last-first + 1);
    }
    return ans;
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
    
    cout<<endl<<"Maximum width of BT: " << maxWidth(root)<<endl;
    cout<<endl<<"Maximum Path sum in BT: " << maxSum(root)<<endl;
    
	
	return 0;
}

/*

output:

Maximum width of BT: 7

Maximum Path sum in BT: 430

*/
