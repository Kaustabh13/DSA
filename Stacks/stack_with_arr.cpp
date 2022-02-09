#include <iostream>
using namespace std;

//Stack Initializer

class Stack {
public:
    int size;
    int top;
    int arr[];
};

// Check Size

/**
 * @brief This function is used to check whether the stack is empty or not
 * 
 * @param stack -> The stack 
 * @return -> It returns a boolean which tells whether the stack is empty or not

 */

bool isEmpty(Stack* stack) {
    return stack->top == -1;
}

/**
 * @brief This function is used to check whether the stack is full or not
 * 
 * @param stack -> The stack
 * @return -> It returns a boolean which tells whether the stack is full or not
 */

bool isFull(Stack* stack) {
    return stack->top == stack->size - 1;
}

//Push 

/**
 * @brief This function is used to handle the push functionality
 * 
 * @param stack -> The initial stack
 * @param val -> The new value to be inserted in the stack
 */

void push(Stack* stack, int val) {

    if(isFull(stack)) {
        cout << "Stack Overflow! Stack is full." << endl;
    } else {
        stack->top++;
        stack->arr[stack->top] = val;
        
        cout << "Pushed at position " << stack->top <<  " -> " << val << endl;

    }
}

//Pop

/**
 * @brief This function is used to pop the value from the stack
 * 
 * @param stack -> The stack 
 * @return int -> The popped value
 */

int pop(Stack* stack) {

    int popped = -1;
    if(isEmpty(stack)) {
        cout << "Stack Underflow! Stack is empty." << endl;
    } else {
        int val = stack->arr[stack->top];
        stack->top--;
        popped = val;
        
        cout << "The popped item is -> " << popped << endl;

    }

    return popped;
}

//Peek

/**
 * @brief This function is used to peek at the stack
 * 
 * @param stack -> The stack
 * @param position -> The position to be peeked at
 */

void peek(Stack* stack, int position) {
    //[1,2,3]
    int val = stack->top - position + 1;

    if(val < 0) {
        cout << "This position is invalid/unavailable in the stack" << endl;
    } else{
        cout << "The item at position " << position << " -> "  << stack->arr[val] << endl;
    }
}

/**
 * @brief This main function acting as initializer
 * 
 * @return int 
 */

int main() {

    Stack * sp = new Stack();
    sp->size = 6;
    sp->top = -1;

    push(sp, 1);
    push(sp, 2);
    push(sp, 3);

    cout << endl;
    pop(sp);
    cout << endl;
  
    for(int i = 1; i <= sp->top + 1; i++) {
        peek(sp, i);
    }


    return 0;
}

