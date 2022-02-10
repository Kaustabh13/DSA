#include <iostream>
using namespace std;

//Queue Initializer

class Queue {

public:
    int front;
    int rear;
    int size;
    int arr[];
};

//Check Size

/**
 * @brief THis function is used to check whether the Queue is empty or not
 * 
 * @param q -> The queue
 * @return -> A boolean which tells whether the Queue is empty or not 
 */

bool isEmpty(Queue* q) {
    return q->rear == q->front;
}

/**
 * @brief THis function is used to check whether the Queue is full or not
 * 
 * @param q -> The queue
 * @return -> A boolean which tells whether the Queue is full or not 
 */

bool isFull(Queue* q) {
    return q->rear == q->size - 1;
}

//Enque

/**
 * @brief This function is used to enqueue in the queue
 * 
 * @param q -> The queue
 * @param val -> The value to be inserted
 */

void enqueue(Queue* q, int val) {

    if(isFull(q)) {
        cout << "Queue Overflow! Queue is full" << endl;
    } else {
        q->rear++;
        q->arr[q->rear] = val;

        cout << "Enqueued in queue -> " << val << endl;
    }
}

//Dequeue

/**
 * @brief This function is used to dequeue the value
 * 
 * @param q -> The queue 
 */

void dequeue(Queue* q) {

    if(isEmpty(q)) {
        cout << "Queue Underflow! Queue is empty" << endl;
    } else {
        q->front++;
        int val = q->arr[q->front];
        cout << "Dequed value -> " << val << endl;
    }
}

//Peek

/**
 * @brief This function is used to peek the queue
 * 
 * @param q -> The queue
 * @param position -> The position to be picked at
 */

void peek(Queue* q, int position) {

    if(position > q->rear) {
        cout << "Invalid peek position" << endl;
        return;
    }

    if(isEmpty(q)) {
        cout << "Queue Underflow! Queue is empty";
    } else {
        cout << q->arr[position] << endl;
    }
}

//Check Values

/**
 * @brief This function is used to peek the first value
 * 
 * @param q -> The queue
 */

void frontVal(Queue* q) {

    if(isEmpty(q)) {
        cout << "Queue Underflow! Queue is empty" << endl;
    } else {
        cout << "Front val -> " << q->arr[q->front + 1] << endl;
    }
    
}

/**
 * @brief This function is used to peek the rear value
 * 
 * @param q -> The queue
 */

void rearVal(Queue* q) {

    if(isEmpty(q)) {
        cout << "Queue Underflow! Queue is empty" << endl;
    } else {
        cout << "Rear val -> " << q->arr[q->rear] << endl;
    }
}

/**
 * @brief This main function acting as initializer
 * 
 * @return int 
 */

int main() {

    Queue *q = new Queue();
    q->front = -1;
    q->rear = -1;
    q->size = 10;

    enqueue(q, 2);
    enqueue(q, 12);
    enqueue(q, 22);
    enqueue(q, 32);
    dequeue(q);
 
    if(isEmpty(q)) {
        cout << "Queue is empty" << endl;
    }

    if(isFull(q)) {
        cout << "Queue is full" << endl;
    }
    
    cout << "Peek values" << endl;

    for(int i = 1; i <= q->rear; i++) {
        peek(q,q->front + i);
    }

    frontVal(q);
    rearVal(q);
    return 0;
}