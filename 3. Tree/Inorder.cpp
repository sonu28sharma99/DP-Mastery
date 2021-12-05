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

void PreOrderIterative(Node*root){
    if(root==NULL)
        return;
    
    // create a stack
    stack<Node*> stack;
    stack.push(root);

    while(!stack.empty()){
        Node*curr = stack.top();
        stack.pop();
        cout << curr->data << " ";

        // if right subtree is present
        // then fill into the stack
        if(curr->right)
            stack.push(curr->right);
        // if left subtree is present
        // then fill into the stack
        if(curr->left)
            stack.push(curr->left);
    }
}


void InOrderIterative(Node*root){
    // create a stack
    stack<Node*> stack;

    // assign root to curr node
    Node*curr = root;

    while(curr!=NULL || !stack.empty()){
        if(curr!=NULL){
            stack.push(curr);
            curr = curr->left;
        }
        else{
            curr = stack.top();
            cout << curr->data << " ";
            stack.pop();
            curr = curr->right;
        }
    }
}

void PostOrderIterative(Node*root) {
	if (root == NULL)
		return;

	stack<Node*>s;
	s.push(root);
	// answer stack will be the int type
	stack<int> ans;

	while (!s.empty()) {

		Node*curr = s.top();
		s.pop();
		ans.push(curr->data);

		// if any node present in left, then push into the stack
		if (curr->left)
			s.push(curr->left);
		// if any node presnet in right, then push into the stack
		if (curr->right)
			s.push(curr->right);
	}
	// now print the answer stack
	while (ans.empty() == false) {
		cout << ans.top() << " ";
		ans.pop();
	}
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