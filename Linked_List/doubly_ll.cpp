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
    bool isReverse = false;
    while(current != NULL) {

        cout << current->data << endl;
        if(current->next == NULL && !isReverse) { //If the next node is NULL then, we can reverse it in order to receive the previous node data to verify DLL
            isReverse = true;
            cout << "Reverse Traversal" << endl;
            cout << current->data << endl;
        }
        
        current = isReverse ? current->prev : current->next;
    }    
}

//Insert 

/**
 * @brief This function is used to insert the new node at the root
 * 
 * @param head -> The current head of the node
 * @param data -> The value of data for new node
 * @return Node* -> The new head node
 */

Node* insertAtFirst(Node* head, int data) { 

    //Current:- NULL<-[6]-><-[8]-><-[9]->NULL
    //Target:- NULL<-[data]-><-[6]-><-[8]-><-[9]->NULL

    Node* ptr = head;
    Node* node = new Node(); //New Node
    node->data = data;
    node->prev = NULL;
    node->next = ptr;
    ptr->prev = node;
    head = node;
    return head;
}

/**
 * @brief This function is used to insert the node at the last
 * 
 * @param head -> The current head of the node
 * @param data -> The value of data for the new node
 * @return Node* -> The head node for traversal
 */

Node* insertAtLast(Node* head, int data) {

    //Current:- NULL<-[6]-><-[8]-><-[9]->NULL
    //Target:- NULL<-[6]-><-[8]-><-[9]-><-[data]->NULL

    Node* current = head;
    Node* node = new Node();
    node->data = data;
    node->next = NULL;

    while(current->next != NULL) {
        current = current->next;
    }

    node->prev = current;
    current->next = node;

    return head;
}

/**
 * @brief This function is used to insert after a node
 * 
 * 
 * @param current -> The current node after which the data needs to be inserted
 * @param data -> The new value of data for the new node
 * @return Node* -> The current node
 */

Node* insertAfterNode(Node* head, Node* current, int data) { //Added head in parameter to just return head and go through same traversal

    //Current:- NULL<-[6]-><-[8]-><-[9]->NULL
    //Target:- NULL<-[6]-><-[data]-><-[8]-><-[9]->NULL ==> With current as 6

    if(current == NULL) return head;
    if(current->next == NULL) return insertAtLast(head, data);

    Node* node = new Node();
    node->data = data;
    node->prev = current;
    node->next = current->next;
    current->next->prev = node;
    current->next = node;

    return head;
}

/**
 * @brief This function is used to insert before a node
 * 
 * 
 * @param current -> The current node before which the data needs to be inserted
 * @param data -> The new value of data for the new node
 * @return Node* -> The current node
 */

Node* insertBeforeNode(Node* head, Node* current, int data) { //Added head in parameter to just return head and go through same traversal

    //Current:- NULL<-[6]-><-[8]-><-[9]->NULL
    //Target:- NULL<-[6]-><-[data]-><-[8]-><-[9]->NULL ===> With current as 8

    if(current == NULL) return head;
    if(current->prev == NULL) return insertAtFirst(head, data);

    Node* node = new Node();
    node->data = data;
    node->prev = current->prev;
    current->prev->next = node;
    node->next = current;
    current->prev = node;

    return head;
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

    head = insertBeforeNode(head, first, 22);
    traverseDLL(head);
    return 0;
}