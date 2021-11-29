#include<iostream>
using namespace std;

// Linked List Class
class Node {
public:
    int data;
    Node*next;

    // constructor to fill data in the linkedlist
    Node(int d) {
        data = d;
        next = NULL;
    }
};

// Function to compute length of the linked list
int listLength(Node*head) {
    int length = 0;
    while (head) {
        head = head->next;
        length++;
    }
    return length;
}

// Function to insert data at the head of he linked list
void insertAtHead(Node*&head, int d) {
    if (head == NULL) {
        head = new Node(d);
        return;
    }

    Node*temp = new Node(d);
    temp->next = head;
    head = temp;
}

// Function to insert data at the end of the linked list
void insertAtEnd(Node*&head, int d) {
    if (head == NULL) {
        insertAtHead(head, d);
        return;
    }

    Node*temp = head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = new Node(d);
}

// Function to insert data in the middle of the linked list
void insertInMiddle(Node*&head, int d, int position) {
    if (head == NULL || listLength(head) == 0) {
        insertAtHead(head, d);
        return;
    }

    if (position > listLength(head)) {
        insertAtEnd(head, d);
        return;
    }

    Node*temp = head;
    // reach to the middle
    int count = position - 1;
    while (count--) {
        temp = temp->next;
    }

    Node*dummy = temp->next;
    temp->next = new Node(d);
    temp->next->next = dummy;
}

// Function to print linked list
void printList(Node*head) {
    while (head) {
        cout << head->data << "->";
        head = head->next;
    }
    cout << "NULL" << endl;
}

void deleteAtHead(Node*&head) {
    if (head == NULL) return;
    Node*temp = head->next;
    delete head;
    head = temp;
}

void deleteAtEnd(Node*&head) {
    if (head == NULL) return;
    Node*temp = head;
    while (temp->next->next != NULL) {
        temp = temp->next;
    }
    Node*garbage = temp->next;
    temp->next = NULL;
    delete garbage;
}

void deleteInMiddle(Node*&head, int position) {
    if (head == NULL or position <= 0) return;
    if (position > listLength(head)) {
        deleteAtEnd(head);
        return;
    }

    int pos = position - 1;
    Node*temp = head;
    while (pos--) {
        temp = temp->next;
    }
    Node*garbage = temp->next;
    temp->next = temp->next->next;
    delete garbage;
}



// Main driver function
int main() {
    Node*head = NULL;
    int n; cin >> n;
    while (n--) {
        int data; cin >> data;
        insertAtHead(head, data);
    }

    // deleteAtEnd(head);
    deleteInMiddle(head, -10);
    printList(head);

}