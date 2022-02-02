#include<iostream>
using namespace std;

//Initializer

class Node {
public:
    int data;
    Node* prev;
    Node* next;
};

//Traverse

/**
 * @brief This function is used to traverse through the Doubly Linked List
 * 
 * @param head -> The root node of the DLL
 */

void traverseDLL(Node* head) {
    Node* current = head;
    while(current != NULL) {
        cout << current->data << endl;
        current = current->next;
    }
}

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
    head->prev = NULL;

    first->data = 8;
    first->next = second;
    first->prev = head;

    second->data = 9;
    second->next = NULL;
    second->prev = first; 

    traverseDLL(head);
    return 0;
}