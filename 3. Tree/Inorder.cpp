#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
        int data;
        Node*left;
        Node*right;
    
    Node(int d){
        data = d;
        left = right = NULL;
    }
};

void PreOrder(Node*root){
    if(root==NULL)
        return;
    
    cout << root->data << " ";
    PreOrder(root->left);
    PreOrder(root->right);
}

void InOrder(Node*root){
    if(root==NULL)
        return;
    InOrder(root->left);
    cout << root->data << " ";
    InOrder(root->right);
}

void PostOrder(Node*root){
    if(root==NULL)
        return;
    PostOrder(root->left);
    PostOrder(root->right);
    cout << root->data << " ";
}



int main(){
/* Constructed binary tree is
              1
            /   \
          2      3
        /  \
      4     5
    */
    Node *root = new Node(1);
    root->left        = new Node(2);
    root->right       = new Node(3);
    root->left->left  = new Node(4);
    root->left->right = new Node(5);
}