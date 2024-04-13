//Header file to implement stack ADT using singly linked list
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

//Class that contains the list of operations and structures needed
class stack{
    
    private:
        struct node{
            char data;
            struct node* next;
        };
        struct node* top;

        struct op_info{
            int precedence;           
            char associativity;
        };

    public:

        char infix_exp[20];
        char postfix_exp[20];  
        int index;

        stack(){
            top=nullptr;
            index=-1;
        }

        bool isempty();
        bool isoperator(char);
        op_info get_op_info(char);
        char push(char);
        char insert(char);
        char pop();
        char peek();
        void display();
        char conversion(char*);
        char evaluation(char*);
        char check(char *, int);
        int compute(char, char, char);
};

//Method to check if the stack is empty. Time Complexity O(1)
bool stack :: isempty(){
    return top==nullptr;
}

//Method to check if the character is an operator. Time Complexity O(1)
bool stack :: isoperator(char ch){
    return ch=='+' || ch=='-' || ch=='*' || ch=='/' || ch=='%' || ch=='=';
}


//Method to get the operator info for an operator. Time Complexity O(1)
stack :: op_info stack :: get_op_info(char op){
    struct op_info info;

    switch(op){
        case '+':
        case '-':
            info.precedence=1;
            info.associativity='L';
            break;
        
        case '*':
        case '/':
        case '%':
            info.precedence=2;
            info.associativity='L';
            break;
        
        case '=':
            info.precedence=0;
            info.associativity='R';
            break;
        
        default:
            info.precedence=-1;
            info.associativity='L';
    }
    return info;
}

//Method to push a character into the stack. Time Complexity O(1)
char stack :: push(char element){
    struct node* newnode=(struct node*)malloc(sizeof(struct node));
    newnode->data=element;
    newnode->next=top;
    top=newnode;
    return '*'; 
}

//Method to insert a character into the postfix expression. Time Complexity O(1)
char stack::insert(char element) {
    if (index < 20) {  
        index++;
        postfix_exp[index] = element;
    } 
    else {
        printf("\nPostfix expression overflow!\n");
    }
    return '*';
}


//Method to delete the topmost element from the stack. Time Complexity O(1)
char stack :: pop(){
    struct node* temp=top;
    if(isempty()){
        printf("Stack Underflow\n");
        return '-';
    }
    else{
        top=top->next;
        char del_val=temp->data;
        free(temp);
        return del_val;
    }
}

//Method to access the topmost element of the stack. Time Complexity O(1)
char stack :: peek(){
    struct node* temp=top;
    if(isempty()){
        printf("\nStack Underflow ");
        return '-';
    }
    else{
        return temp->data;
    }
}

//Method to display the contents of the stack. Time Complexity O(n)
void stack :: display(){
    struct node* temp=top;
    if(isempty()){
        printf("\nStack is empty");
    }
    else{
        printf("The contents of the stack are: ");
        while(temp!=nullptr){
            printf("%c ",temp->data);
            temp=temp->next;
        }
    }
}

//Method to check the precedence and associativity of the operands and insert accordingly. Time Complexity O(n)
char stack::check(char* infix_exp, int n) {
    for (int i = 0; i < n; i++) {
        if (isalnum(infix_exp[i])) {
            insert(infix_exp[i]);
        } else if (isoperator(infix_exp[i])) {
            while (!isempty() && get_op_info(infix_exp[i]).precedence <= get_op_info(peek()).precedence) {
                char op = pop();
                insert(op);
            }
            push(infix_exp[i]);
        }
    }
    while (!isempty()) {
        char op = pop();
        insert(op);
    }
    insert('\0'); //End Marker
    return '*';  
}

// Method to perform the operation on the operands. Time Complexity O(1)
int stack::compute(char op1, char op2, char op) {
    int result;

    switch (op) {
        case '+':
            result = int(op1) + int(op2);
            break;

        case '-':
            result = int(op1) - int(op2);
            break;

        case '*':
            result = int(op1) * int(op2);
            break;

        case '/':
            if (int(op2) != 0) {
                result = int(op1) / int(op2);
            } else {
                printf("Error: Division by zero\n");
                return 0;  // Return 0 in case of division by zero
            }
            break;

        case '%':
            if (int(op2) != 0) {
                result = int(op1) % int(op2);
            } else {
                printf("Error: Modulo by zero\n");
                return 0;  // Return 0 in case of modulo by zero
            }
            break;

        case '=':
            result = int(op2);
            break;

        default:
            printf("Invalid Operator!\n");
            return 0;  // Return 0 for unknown operators
    }
    return result;
}

//Method to convert infix expression to postfix expression. Time Complexity O(n)
char stack :: conversion(char* infix_exp){
    int n=strlen(infix_exp);

    if(!n){
        printf("\nExpression empty!");
        return '-';
    }
    else{
        check(infix_exp, n);
    }

}

// Method to evaluate the postfix expression. Time Complexity O(n)
char stack::evaluation(char* postfix_exp) {
    int n = strlen(postfix_exp);

    for (int i = 0; postfix_exp[i]; ++i) {
         
        // If the scanned character is an operand 
        // (number here), push it to the stack.
        if (isdigit(postfix_exp[i]))
            push(postfix_exp[i] - '0');
 
        // If the scanned character is an operator, 
        // Pop two elements from stack apply the operator
        else {
            int val1 = pop();
            int val2 = pop();
            switch (postfix_exp[i]) {
            case '+':
                push(val2 + val1);
                break;
            case '-':
                push(val2 - val1);
                break;
            case '*':
                push(val2 * val1);
                break;
            case '/':
                push(val2 / val1);
                break;
            case '%':
                push(val1%val2);
                break;
            case '=':
                push(val2);
                break;
            }
        }
    }
    return pop();
}
