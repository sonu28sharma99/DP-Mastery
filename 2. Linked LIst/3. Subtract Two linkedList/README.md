
```c++
#include<iostream>
using namespace std;

// creating node class
class Node {
public:
    int data;
    Node*next;

    Node(int d) {
        data = d;
        next = NULL;
    }
};

// insertion in head
void insertAtHead(Node*&head, int d) {
    if (head == NULL) {
        head = new Node(d);
        return;
    }
    Node*temp = new Node(d);
    temp->next = head;
    head = temp;
}

// print the list
void printList(Node*head) {
    while (head != NULL) {
        cout << head->data << "->";
        head = head->next;
    }
    cout << endl;
}

// reverse the list
Node*reverseList(Node*&head) {
    if (head == NULL or head->next == NULL)
        return head;
    // create 3 temp node
    Node*prevNode = NULL, *currentNode = head, *nextNode = NULL;
    while (currentNode != NULL) {
        nextNode = currentNode->next;
        currentNode->next = prevNode;
        prevNode = currentNode;
        currentNode = nextNode;
    }
    return head = prevNode;
}


Node*addTwoNumber(Node*l1, Node*l2) {
    // check if list l1 if empty return l2
    // or l2 is empty return l1
    if (l1 == NULL || l2 == NULL)
        return l1 != NULL ? l1 : l2;

    // reverse both list for doing addition operation
    Node*l1Head = reverseList(l1);
    Node*l2Head = reverseList(l2);

    // creating dummy node for storing answer
    // creating ans node for storing and traversing
    // creating a carry variable for storing carry
    Node*dummy = new Node(-1);
    Node*ans = dummy;
    int carry = 0;

    while (l1Head != NULL || l2Head != NULL || carry != 0) {
        int sum = carry + (l1Head != NULL ? l1Head->data : 0) + (l2Head != NULL ? l2Head->data : 0);
        int unitDigit = sum % 10;
        carry = sum / 10;

        // answer point to the unitDigit
        ans->next = new Node(unitDigit);
        ans = ans->next;

        // move pointer of l1 and l2 head
        if (l1Head != NULL)
            l1Head = l1Head->next;
        if (l2Head != NULL)
            l2Head = l2Head->next;
    }
    return reverseList(dummy->next);
}


// Subtract two linked list
Node*subtractTwoLinkedList(Node*l1, Node*l2) {
    Node*dummy = new Node(-1);
    Node*ans = dummy;

    l1 = reverseList(l1);
    l2 = reverseList(l2);
    int borrow = 0;
    while (l1) {
        int sum = borrow + l1->data - (l2 ? l2->data : 0);
        if (sum < 0) {
            sum += 10;
            borrow = -1;
        } else {
            borrow = 0;
        }
        ans->next = new Node(sum);
        ans = ans->next;

        l1 = l1->next;
        l2 = l2 ? l2->next : l2;
    }
    return reverseList(dummy->next);
}












// Main driver functoin
int main() {
    Node*list1 = NULL;
    Node*list2 = NULL;

    // input data in first list
    int n1; cin >> n1;
    while (n1--) {
        int data1; cin >> data1;
        insertAtHead(list1, data1);
    }

    // input data in second list
    int n2; cin >> n2;
    while (n2--) {
        int data2; cin >> data2;
        insertAtHead(list2, data2);
    }

    printList(list1);
    printList(list2);

    Node*ans = subtractTwoLinkedList(list1, list2);
    printList(ans);

}
```

## input:
```
7 
7 6 5 4 3 2 1
3
9 8 7
```

## output:
```
1->2->3->4->5->6->7->
7->8->9->
1->2->3->3->7->7->8->
```