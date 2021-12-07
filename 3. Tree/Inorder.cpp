#include<bits/stdc++.h>
using namespace std;

// CLASS OF TREE NODE
class Node {
public:
    int data;
    Node*left;
    Node*right;

    Node(int d) {
        data = d;
        left = right = NULL;
    }
};

// PREORDER TRAVERSAL OF BINARY TREE
// USING RECURSION
void PreOrder(Node*root) {
    if (root == NULL)
        return;

    cout << root->data << " ";
    PreOrder(root->left);
    PreOrder(root->right);
}

// INORDER TRAVERSAL OF BINARY TREE
// USING RECURSION
void InOrder(Node*root) {
    if (root == NULL)
        return;
    InOrder(root->left);
    cout << root->data << " ";
    InOrder(root->right);
}

// POSTORDER TRAVERSAL OF BINARY TREE
// USING RECURSION
void PostOrder(Node*root) {
    if (root == NULL)
        return;
    PostOrder(root->left);
    PostOrder(root->right);
    cout << root->data << " ";
}

// PREORDER TRAVERSAL OF BINARY TREE
// ITERATIVE WAY
void PreOrderIterative(Node*root) {
    if (root == NULL)
        return;

    // create a stack
    stack<Node*> stack;
    stack.push(root);

    while (!stack.empty()) {
        Node*curr = stack.top();
        stack.pop();
        cout << curr->data << " ";

        // if right subtree is present
        // then fill into the stack
        if (curr->right)
            stack.push(curr->right);
        // if left subtree is present
        // then fill into the stack
        if (curr->left)
            stack.push(curr->left);
    }
}

// INORDER TRAVERSAL OF BINARY TREE
// ITERATIVE WAY
void InOrderIterative(Node*root) {
    // create a stack
    stack<Node*> stack;

    // assign root to curr node
    Node*curr = root;

    while (curr != NULL || !stack.empty()) {
        if (curr != NULL) {
            stack.push(curr);
            curr = curr->left;
        }
        else {
            curr = stack.top();
            cout << curr->data << " ";
            stack.pop();
            curr = curr->right;
        }
    }
}

// POSTORDER TRAVERSAL OF BINARY TREE
// ITERATIVE WAY
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


// FINDING HEIGHT OF BINARY TREE
int Height(Node*root) {
    // if there is no root, height will be zero
    if (root == NULL)
        return 0;
    // left subtree height
    int leftHeight = Height(root->left);
    // right subtree height
    int rightHeight = Height(root->right);
    // max of leftsubtree and rightsubtree will be our answer
    return max(leftHeight, rightHeight) + 1;
}

// PRINTING KTH LEVEL OF THE BINARY TREE
void printKthLevel(Node*root, int k) {
    if (root == NULL)
        return;
    // if k == 1; that mean this is the desired level
    // for which we have to print
    if (k == 1) {
        cout << root->data << " ";
        return;
    }

    // call left and right subtree of root
    printKthLevel(root->left, k - 1);
    printKthLevel(root->right, k - 1);
    return;
}

// LEVEL ORDER TRAVERSAL OF BINARY TREE
// USING RECURSION
// TIME     : O(N^2)
// SPACE    : O(1)
void LevelOrder(Node*root) {
    if (root == NULL)
        return;

    // computer the height of tree
    int H = Height(root);

    // iterate 0 to H(Including) for printing level by level
    for (int i = 0; i <= H; i++) {
        printKthLevel(root, i);
        // cout << endl;
    }
    return;
}

// TIME : O(N)
// SPACE : O(N)
void LevelOrderIterative(Node*root) {
    // if root is empty then simply return
    if (root == NULL)
        return;

    // create a queue
    queue<Node*> q;
    q.push(root);

    // store the current node in queue
    Node*curr = NULL;


    while (!q.empty()) {
        curr = q.front();
        q.pop();

        cout << curr->data << " ";
        // if curr node has any left or right subtree 
        // then push it into the queue
        if (curr->left)
            q.push(curr->left);
        if (curr->right)
            q.push(curr->right);
    }
}



// MAIN DRIVER FUNCTION
int main() {
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

    PreOrder(root);             cout << endl;   // 1 2 4 5 3
    PreOrderIterative(root);    cout << endl;
    InOrder(root);              cout << endl;   // 4 2 5 1 3
    InOrderIterative(root);     cout << endl;
    PostOrder(root);            cout << endl;   // 4 5 2 3 1
    PostOrderIterative(root);   cout << endl;
    LevelOrder(root);           cout << endl;   // 1 2 3 4 5
    LevelOrderIterative(root);  cout << endl;

}