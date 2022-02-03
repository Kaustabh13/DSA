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

//Delete 

/**
 * @brief This function is used to delete the first node
 * 
 * @param head -> The root of the node
 * @return Node* -> The new head 
 */

Node* deleteAtFirst(Node* head) {

    Node* ptr = head; //[6]->[7]->[8]
    Node* tempNode = head;

    while(ptr->next != head) {
        ptr = ptr->next;
    }
    
    ptr->next = tempNode->next;
    free(tempNode); //Free Memory
    head = ptr;

    return head;
}

/**
 * @brief This function is used to delete the last node and connect the previous of last to the head node to make it circular
 * 
 * @param head -> The root node of the CLL
 * @return Node* -> The root noed of CLL
 */

Node* deleteAtLast(Node* head) {

    Node* ptr = head; //[6]->[8]->[9]
    Node* tempNode = head;
    Node* prev = NULL;

    while(ptr->next != head) {
        prev = ptr;
        ptr = ptr->next;
    }
    
    free(ptr);
    prev->next = head;

    return head;
}

//Reverse

/**
 * @brief This function is used to reverse the CLL
 * 
 * @param head -> The current root of the node
 * @return Node* -> The updated root of the node
 */

Node* reverse(Node* head) {

    //Current:- [6]->[8]->[9]->Head 6 is Head
    //Target:-  Head<-[6]<-[8]<-[9] 9 is Head

    Node* prev = NULL;
    Node* current = head;
    Node* next = NULL;

    while(current->next != head) { 
       next = current->next; 
       current->next = prev; 
       prev = current; 
       current = next; 
    }

    current->next = prev;
    head->next = current;
    head = current;

    return head;    
}

//Searching & Matching in CLL is same as Linked List

//Main Function

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
    cout << "Before Reversal" << endl;
    head = reverse(head);
    cout << "After Reversal" << endl;

    traverseLL(head);

    return 0;
}