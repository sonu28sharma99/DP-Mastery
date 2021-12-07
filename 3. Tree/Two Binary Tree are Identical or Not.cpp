#include<bits/stdc++.h>
using namespace std;

// Binary Tree Node Class
class Node {
public:
    int data;
    Node * left, *right;

    // constructor
    Node(int d) {
        data = d;
        left = right = NULL;
    }
};


void PreOrder(Node*root) {
    if (root == NULL)
        return;
    cout << root->data << " ";
    PreOrder(root->left);
    PreOrder(root->right);
}

bool isIdentical(Node*t1, Node*t2) {
    // if both tree is null then return true
    if (!t1 and !t2)
        return true;

    return (
               (t1 && t2) &&                // t1 and t2 is not null 
               (t1->data == t2->data) &&    // t1 data is equals to t2 data
               isIdentical(t1->left, t2->left) &&   // same steps for left subtree 
               isIdentical(t1->right, t2->right)    // same steps for right subtree
           );
}

int main() {
    // construct the first tree
    Node*t1 = NULL;
    t1 = new Node(15);
    t1->left = new Node(10);
    t1->right = new Node(20);
    t1->left->left = new Node(8);
    t1->left->right = new Node(12);
    t1->right->left = new Node(16);
    t1->right->right = new Node(25);

    // construct second tree
    Node*t2 = NULL;
    t2 = new Node(15);
    t2->left = new Node(10);
    t2->right = new Node(20);
    t2->left->left = new Node(8);
    t2->left->right = new Node(12);
    t2->right->left = new Node(16);
    t2->right->right = new Node(25);

    // preorder traversal of tree 1
    PreOrder(t1);  cout << endl;
    // preorder traversal of tree 2
    PreOrder(t2);  cout << endl;

    isIdentical(t1, t2) == true ? cout << "yes" : cout << "no";
}



