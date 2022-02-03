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

//Delete 

/**
 * @brief This function is used to delete the head node and replace the head with next available node.
 * We are assuming that this head is not the only node
 * 
 * @param head -> The root of the DLL
 * @return Node* -> The new head node
 */

Node* deleteFirstNode(Node* head) {

    //Current:- NULL<-[6]-><-[8]-><-[9]->NULL
    //Target:- NULL<-[8]-><-[9]->NULL


    if(head->next == NULL) return head; //In case of single node DLL, just return the node. We can delete this as well to free memory, but keeping it for now

    Node* current = head;

    current->next->prev = current->prev;

    head = current->next;

    free(current); //Free Memory

    return head;
}

/**
 * @brief This function is used to delete the last node 
 * 
 * @param head -> The root of the node
 * @return Node* -> The head of the node for traversal
 */

Node* deleteLastNode(Node* head) {

    //Current:- NULL<-[6]-><-[8]-><-[9]->NULL
    //Target:- NULL<-[6]-><-[8]->NULL

    Node* current = head;

    while(current->next != NULL) {
        current = current->next;
    }

    current->prev->next = current->next;
    free(current);
    return head;
}

/**
 * @brief This function is used to delete a specific node, it can be the middle node, first node, second node or any other node in the growing DLL
 * 
 * @param head -> The root node to handle the edge cases
 * @param node -> The node to be deleted
 * @return Node* -> The head node for traversal
 */

Node* deleteSpecificNode(Node* head, Node* node) {

     //Current:- NULL<-[6]-><-[8]-><-[9]->NULL
    //Target:- NULL<-[6]-><-[9]->NULL ==> Assuming node to be deleted is 8 or the middle node here

    if(node->prev == NULL) return deleteFirstNode(head); //Edge case
    if(node->next == NULL) return deleteLastNode(head); //Edge case

    node->next->prev = node->prev;
    node->prev->next = node->next;

    free(node); //Free Memory

    return head;
}

//Reverse

/**
 * @brief This function is used to reverse DLL
 * 
 * @param head -> The root node of the DLL
 * @return Node* -> The new head/root of the DLL
 */

Node* reverse(Node* head) {

    //Current:- NULL<-[6]-><-[8]-><-[9]->NULL
    //Target:- NULL<-[9]-><-[8]-><-[6]->NULL

    Node* prev = NULL;
    Node* current = head;
    Node* next = NULL;

    while(current->next != NULL) { 
        next = current->next; 
        current->next = prev; 
        prev = current; 
        current->prev = next; 
        current = next; 
    }

    current->next = prev;
    current->prev = NULL;
    head = current;

    return head;

}

//Main Function

//Search & Match Works the same way as LL

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
    cout << "Before Reveral" << endl;
    head = reverse(head);
    cout << "After Reveral" << endl;
    traverseDLL(head);
    return 0;
}