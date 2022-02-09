#include <iostream>
using namespace std;

//Node Initializer

class Node
{
 public:
    int data;
    Node* next;
};

//Traverse

/**
 * @brief This function is used to traverse through the Linked List
 * 
 * @param head -> The head of the node
 */

void traverseLL(Node* head) {

    Node* ptr = head;

    while(ptr != NULL) {
        cout << ptr->data << "\n";
        ptr = ptr->next;
    }
}

//Check Size

/**
 * @brief This function is used to check whether the stack is empty or not
 * 
 * @param head -> The top of the stack
 * @return -> A boolean which tells whether the stack is empty or not
 */

bool isEmpty(Node* head) {
    return !head;
}

//Push

/**
 * @brief This function is used to push the new node in the stack
 * 
 * @param head -> The head of the node/the top
 * @param data -> The data for new node
 * @return Node* -> The new top/head
 */

Node* push(Node* head, int data) {

    Node* node = new Node();
    node->next = head;
    node->data = data;

    head = node;
    return head;
}

//Pop

/**
 * @brief This function is used to pop the data from the stack
 * 
 * @param head -> The top of the stack
 * @return int -> The popped element
 */

Node* pop(Node* head) {

    if(isEmpty(head)) {
        cout << "Stack Underflow. Stack is empty" << endl;
    } else {
        Node* prev = head;
        head = prev->next;
        cout << "Popped element -> " << prev->data << endl;
        free(prev);        
    }

    return head;
}

//Peek

/**
 * @brief This function is used to peek at the stack
 * 
 * @param top -> The top of the stack
 * @param position -> The peek position
 */

void peek(Node* top, int position) {

    if(isEmpty(top)) {
        cout << "Stack Underflow! Stack is empty." << endl;
        return;
    }

    int i = 1;

    if(position < i) {
        cout << "Invalid position requested" << endl;
        return;
    }

    Node* ptr = top;

    while(ptr->next && i != position) {
        ptr = ptr->next;
        i++;
    }

    if(i == position) {
       cout << "The item at " << position << " -> " << ptr->data << endl;
    } else {
       cout << "Invalid position requested" << endl;
    }   
}

//Stack Top

/**
 * @brief This function is used to print the stack top
 * 
 * @param top -> The top of the stack
 */

void stackTop(Node* top) {
    cout << "Stack top -> " << top->data << endl;
}

//Stack Bottom

/**
 * @brief This function is used to print the stack bottom
 * 
 * @param top -> The top of the stack
 */

void stackBottom(Node* top) {

    Node* ptr = top;
    while(ptr->next) {
        ptr = ptr->next;
    }

    cout << "Stack Bottom -> " << ptr->data << endl;
}

/**
 * @brief This main function acting as initializer
 * 
 * @return int 
 */

int main() {

    Node* head = NULL;

    head = push(head, 2);
    head = push(head, 12);
    head = push(head, 22);
    head = push(head, 32);

    traverseLL(head);

    head = pop(head);

    traverseLL(head);

    stackTop(head);

    stackBottom(head);

    peek(head, 3);

    return 0;
}