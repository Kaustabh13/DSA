#include<iostream>
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
 * @brief This function is used to traverse through the Circular Linked List
 * 
 * @param head -> The head of the node
 */

void traverseLL(Node* head) {

    Node* ptr = head;

    while(ptr->next != head) {
        cout << ptr->data << "\n";
        ptr = ptr->next;
    }

    cout << ptr->data << "\n";
}

//Insert 

/**
 * @brief This function is used to insert a new node at first  
 * 
 * @param head -> The head of the pointer
 * @param data -> The data for new node
 * @return Node* -> The new head node
 */

Node* insertAtFirst(Node* head, int data) {

    Node *ptr = head;
    Node *node = new Node(); //[6]->[8]->[9]
    node->data = data;      // | <--[7]--> |
    node->next = head;

    while(ptr->next != head) {
        ptr = ptr->next;
    }

    ptr->next = node;
    head = node;
    return head;
}

/**
 * @brief This function is used to insert the node at the last of the circular linked list
 * 
 * @param head -> The root of the CLL
 * @param data -> The data for the new Node
 * @return Node* -> The root node
 */

Node* insertAtLast(Node* head, int data) {

    Node *ptr = head;
    Node *node = new Node(); //[6]->[8]->[9] |
    node->data = data;      //       <--[7]-->
    node->next = head;

    while(ptr->next != head) {
       ptr = ptr->next;
    }                       
    
    ptr->next = node;

    return head;
}

/**
 * @brief This main function acting as initializer
 * 
 * @return int 
 */

int main() {
    
    Node* head = NULL;
    Node* first = NULL;
    Node* second = NULL;

    head = new Node();
    first = new Node();
    second = new Node();

    head->data = 6;
    head->next = first;

    first->data = 8;
    first->next = second;

    second->data = 9;
    second->next = head; //Make it circular by connecting it to the head

    traverseLL(head);
    head = insertAtLast(head, 20);
    traverseLL(head);

    return 0;
}