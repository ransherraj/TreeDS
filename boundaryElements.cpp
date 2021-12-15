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

bool isLeave(Node* root){
    if(root == NULL) return false;
    if(root->left == NULL && root->right == NULL) return true;
    else return false;
}

void printLeaves(Node* root){
    if(root == NULL) return;
    if(isLeave(root)){
        cout<<root->data<<" ";
    }
    printLeaves(root->left);
    printLeaves(root->right);
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
    
	
	zigZag(root);
	cout<<"ZigZag print"<<endl;
	for(int i = 0; i < res.size(); i++){
	    for(int j = 0; j < res[i].size(); j++){
	        cout<<res[i][j]<<" ";
	    }
	    cout<<endl;
	}
	cout<<endl<<"Printing Leaves: "<<endl;
	printLeaves(root);
	return 0;
}

/*


Maximum width of BT: 7

Maximum Path sum in BT: 430
ZigZag print
10 
30 20 
40 50 60 
100 80 70 
90 

Printing Leaves: 
70 90 50 100 

*/
