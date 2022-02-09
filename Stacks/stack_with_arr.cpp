#include <iostream>
using namespace std;

//Stack Initializer

class Stack {
public:
    int size;
    int top;
    char arr[];
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

void push(Stack* stack, char val) {

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

char pop(Stack* stack) {

    char popped = '-';
    if(isEmpty(stack)) {
        cout << "Stack Underflow! Stack is empty." << endl;
    } else {
        char val = stack->arr[stack->top];
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
 * @brief This function is used to match the characters/parenthesis
 * 
 * @param pre -> The pushed value
 * @param post -> The target value
 * @return -> A boolean which tells if characters matched or not
 */

bool matchChar(char pre, char post) {

    if(pre == '(' && post == ')' || pre == '[' && post == ']' || pre == '{' && post == '}') {
        return true;
    }

    return false;
}

//Parenthesis Matching

/**
 * @brief This function is used to check whether the parenthesis is matching or not
 * 
 * @param s -> The string with equation/expression
 * @return -> A boolean which tells whether the parenthesis is matching or not
 */

bool isParenthesisMatching(string s) {

    Stack * sp = new Stack();
    sp->size = s.length();
    sp->top = -1;

    for(int i = 0; i < s.length(); i++) {

        if(s[i] == '(' || s[i] == '[' || s[i] == '{') {
            push(sp, s[i]);
        } else if (s[i] == ')' || s[i] == ']' || s[i] == '}') {

           if(isEmpty(sp)) { return false; }
           
           char popVal = pop(sp);

           if(!matchChar(popVal, s[i])) {
               return false;
           }
        }
    }

    return isEmpty(sp);
}


/**
 * @brief This main function acting as initializer
 * 
 * @return int 
 */

int main() {

    // Stack * sp = new Stack();
    // sp->size = 6;
    // sp->top = -1;

    // push(sp, 'a');
    // push(sp, 'b');
    // push(sp, 'c');

    // cout << endl;
    // pop(sp);
    // cout << endl;
  
    // for(int i = 1; i <= sp->top + 1; i++) {
    //     peek(sp, i);
    // }

    string exp = "8-12-1]+{1-10})";
    if (isParenthesisMatching(exp)) {
        cout << "Patenthesis is matching" << endl;
    } else {
        cout << "Patenthesis is not matching" << endl;
    }

    return 0;
}

