<img src="../../gifs/LinkedList_implementation.gif" />

## Code:
```c++
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
void insertInMiddle(Node*&head, int d, int pos) {
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
void deleteAtHead(Node*&head) {
    if (head == NULL) return;
    Node*temp = head->next;
    delete head;
    head = temp;
}

// DELETION AT THE TAIL
void deleteAtTail(Node*&head) {
    if (head == NULL) return;
    Node*temp = head;
    while (temp->next->next != NULL) {
        temp = temp->next;
    }
    delete temp->next;
    temp->next = NULL;
}

// DELETION AT THE MIDDLE WITH POSITION POS
void deleteInMiddle(Node*&head, int pos) {
    if (head == NULL or pos > listLength(head) or pos < listLength(head))
        return;

    int count = pos - 1;
    Node*temp = head;
    while (count--) {
        temp = temp->next;
    }
    delete temp;
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

    cout << "\ninserting at the tail :-" << endl;
    insertAtTail(head, 100000);
    printList(head);

    cout << "\ninserting in the middle with pos=4 :-" << endl;
    insertInMiddle(head, 200000, 4);
    printList(head);

    cout << "\ndeletion at the head :-" << endl;
    deleteAtHead(head);
    printList(head);

    cout << "\ndeletion at the tail :-" << endl;
    deleteAtTail(head);
    printList(head);


    deleteInMiddle(head, 3);
    printList(head);

}
```

## Output:
```
inserting at head :-
9->8->7->6->5->4->3->2->1->NULL

inserting at the tail :-
9->8->7->6->5->4->3->2->1->100000->NULL

inserting in the middle with pos=4 :-
9->8->7->6->200000->4->3->2->1->100000->NULL

deletion at the head :-
8->7->6->200000->4->3->2->1->100000->NULL

deletion at the tail :-
8->7->6->200000->4->3->2->1->NULL
8->7->6->200000->4->3->2->1->NULL
```