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

//Insert

/**
 * @brief This function is used to insert before the first node
 * 
 * @param head => The head of the node
 * @param data => The data of the new Node
 * @return Node* => The new head
 */

Node* insertAtFirst(Node* head, int data) {

    Node* node = new Node(); 
    node->data = data;       
    node->next = head; //[6]->[8]-[9]->NULL
    head = node;
    return head; //[data]->[6]->[8]-[9]->NULL

}

/**
 * @brief This function is used to insert the data at last
 * 
 * @param head => The head of the node
 * @param data => The new node data
 * @return Node* => Returns the head of the node
 */

Node* insertAtLast(Node* head, int data) {

    Node* current = head; //[6]->[8]->[9]->NULL

    Node* ptr = new Node();
    ptr->data = data;
    ptr->next = NULL;

    while(current->next != NULL ) {
        current = current->next;
    }

    current->next = ptr;
  
    return head; //[6]->[8]-[9]->[data]->NULL
}

/**
 * @brief This function is used to insert the node at an index
 * 
 * @param head -> The head of the node
 * @param index -> The indext at which the node will be inserted
 * @param data -> The data for new node
 * @return Node* => The head of the node
 */

Node* insertAtIndex(Node* head, int index, int data) {

    if(index < 0) return head; //If the index is lower than zero, edge case

    if(index == 0) return insertAtFirst(head, data); //If index is zero then call insertAtFirst Function and return head

    Node* ptr = new Node();
    ptr->data = data;
    Node* prev = head; //[6]->[8]->[9]->NULL
    int i = 0;   
 
    while(i < index - 1) {
        prev = prev->next;
        i++;
    }

    if(prev == NULL) return insertAtLast(head, data); //If pointer overheads/crosses the list insert at the last index to 
                                                     //handle the edge case, we can also throw an erro here to avoid traversal

    ptr->next = prev->next;
    prev->next = ptr;

    return head;
}

//Search and Match

/**
 * @brief This function is used to check whether a value exists or not
 * 
 * @param head -> The head of the node
 * @param value -> The search value
 * @return It returns a boolean stating the value is found in the LL or not
 */

bool doesValueExist(Node* head, int value) {

    Node* node = head;

    while (node != NULL)
    {
       if(node->data == value) return true;
       node = node->next;
    }
    
    return false; 
}

//Delete 

/**
 * @brief This function is used to delete the first node
 * 
 * @param head -> The head of the node
 * @return Node* -> It returns the new node
 */

Node* deleteAtFirst(Node* head) {

    if(head->next == NULL) return head; //If there is only a single node in LL, return head or delete it to free memory

    Node* node = head; //[6]->[8]->[9]->NULL;
    head = node->next;
    free(node); //Free Memory
    return head;
} 

/**
 * @brief This function is used to delete a node at an index
 * 
 * @param head -> The head of node/root of LL
 * @param index -> The index at which the node needs to be delted
 * @return Node* -> The head of the node
 */

Node* deleteAtIndex(Node* head, int index) {

    if(index < 0) return head; //Handle Edge Case 
    if(index == 0) return deleteAtFirst(head); //Delete at first index

    Node* node = head; //[6]->[8]->[9]->NULL;
    int i = 0;

    while(i != index - 1) {
        node = node->next;
        i++;
    }
    
   if(node == NULL) return head; //If index crosses the available position

   Node* tempNode = node->next;
   node->next = tempNode->next;
   free(tempNode);
   return head;
}

//Reverse

/**
 * @brief This function is used to reverse a linked list
 * 
 * @param head -> The root of the node
 * @return Node* -> The new head
 */

Node* reverse(Node* head) {
    //Head->[6]->[7]->[8]->NULL --> Current
    //NULL<-[6]<-[7]<-[8]<-Head --> Reversed/Target

    Node* prev = NULL;
    Node* current = head;
    Node* next = NULL;

    while(current != NULL) {

        next = current->next; //Store the next value for first it will store 7
        current->next = prev; //For first make it NULL and for further replace with previous value
        prev = current; //Store current value in previous
        current = next; //Store next value in current
    }

    return prev;
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
    second->next = NULL;

    traverseLL(head);
    head = reverse(head);
    cout << "After Reversal" << endl;
    traverseLL(head);
    return 0;
}