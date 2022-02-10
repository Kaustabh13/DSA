#include <iostream>
using namespace std;

//Queue Initializer

class CircularQueue {

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

bool isEmpty(CircularQueue* q) {
    return q->rear == q->front;
}

/**
 * @brief THis function is used to check whether the Queue is full or not
 * 
 * @param q -> The queue
 * @return -> A boolean which tells whether the Queue is full or not 
 */

bool isFull(CircularQueue* q) {
    return ((q->rear+1) % (q->size)) == q->front;
}

//Enque

/**
 * @brief This function is used to enqueue in the queue
 * 
 * @param q -> The queue
 * @param val -> The value to be inserted
 */

void enqueue(CircularQueue* q, int val) {

    if(isFull(q)) {
        cout << "Queue Overflow! Queue is full" << endl;
    } else {
        q->rear = (q->rear+1) % (q->size);
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

void dequeue(CircularQueue* q) {

    if(isEmpty(q)) {
        cout << "Queue Underflow! Queue is empty" << endl;
    } else {
        q->front = (q->front+1) % (q->size);
        int val = q->arr[q->front];
        cout << "Dequeued value -> " << val << endl;
    }
}

//Peek

/**
 * @brief This function is used to peek the queue
 * 
 * @param q -> The queue
 * @param position -> The position to be picked at
 */

void peek(CircularQueue* q, int position) {

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

void frontVal(CircularQueue* q) {

    if(isEmpty(q)) {
        cout << "Queue Underflow! Queue is empty" << endl;
    } else {
        cout << "Front val -> " << q->arr[(q->front + 1) % (q ->size)] << endl;
    }
    
}

/**
 * @brief This function is used to peek the rear value
 * 
 * @param q -> The queue
 */

void rearVal(CircularQueue* q) {

    if(isEmpty(q)) {
        cout << "Queue Underflow! Queue is empty" << endl;
    } else {
        cout << "Rear val -> " << q->arr[(q->rear + 1) % (q ->size)] << endl;
    }
}

/**
 * @brief This main function acting as initializer
 * 
 * @return int 
 */

int main() {

    CircularQueue *q = new CircularQueue();
    q->front = 0;
    q->rear = 0;
    q->size = 4;

    enqueue(q, 12);
    enqueue(q, 15);
    enqueue(q, 1);
    enqueue(q, 1);
    dequeue(q);
    dequeue(q);
    enqueue(q, 45);
    enqueue(q, 46);
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