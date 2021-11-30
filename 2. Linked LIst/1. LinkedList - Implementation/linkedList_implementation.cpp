#include<iostream>
using namespace std;

// LINKED LIST CLASS
class Node {
public:
    int data;
    Node*next;

    // constructor
    Node(int d) {
        data = d;
        next = NULL;
    }
};

// FUNCTION TO CALCULATE LENGTH OF THE LIST
int listLength(Node*head) {
    int count = 0;
    while (head != NULL) {
        head = head->next;
        count++;
    }
    return count;
}

// FUNCTION TO INSERT NODE AT THE HEAD
void insertAtHead(Node*&head, int d) {
    // if there is no node present in the list
    if (head == NULL) {
        head = new Node(d);
        return;
    }
    // Otherwise create a new node with data d
    // points to our head
    Node*temp = new Node(d);
    temp->next = head;
    head = temp;
}

// FUNCTION TO INSERT NODE AT THE TAIL OF THE LIST
void insertAtTail(Node*&head, int d) {
    if (head == NULL) {
        insertAtHead(head, d);
        return;
    }

    // react till the end using temp node
    Node*temp = head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    // now create a new node
    temp->next = new Node(d);
}

// FUNCIOTN TO INSERT NODE AT THE MID WITH POSITON POS
void insertAtMiddle(Node*&head, int d, int pos) {
    // if list is empty or pos less than zero
    if (head == NULL or pos <= 0) {
        insertAtHead(head, d);
        return;
    }
    // if pos is greater than length of the list
    if (pos > listLength(head)) {
        insertAtTail(head, d);
        return;
    }

    int cnt = pos - 1;
    Node*temp = head;
    while (cnt--) {
        temp = temp->next;
    }

    Node*newNode = new Node(d);
    newNode->next = temp->next->next;
    temp->next = newNode;
}

// FUNCTION TO PRINT OUR LINKED LIST
void printList(Node*head) {
    while (head != NULL) {
        cout << head->data << "->";
        head = head->next;
    }
    cout << "NULL" << endl;
}

// DELETION AT THE HEAD
void deleteAtHead(Node*head){
    Node*temp=head->next;
    delete head;
    temp=head;
}





// MAIN DRIVER FUNCTION
int main() {
    // initially our linked list is null
    Node*head = NULL;

    // input some data in our linked list
    int n; cin >> n;
    while (n--) {
        int data; cin >> data;
        insertAtHead(head, data);
    }

    cout << "inserting at head :-" << endl;
    printList(head);

    cout << "inserting at the tail :-" << endl;
    insertAtTail(head, 100000);
    printList(head);

    cout << "inserting in the middle with pos=4 :-" << endl;
    insertAtMiddle(head, 200000, 4);
    printList(head);

}