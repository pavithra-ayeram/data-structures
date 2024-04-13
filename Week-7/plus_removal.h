//Header file to implement stack ADT using linked list

#include <stdio.h>
#include <stdlib.h>

class stack{
    private:
        struct node{
            struct node* prev;
            char data;
            struct node* next;
        };

        struct node* top;
    
    public:
        stack(){
            top=nullptr;
        }

        bool isempty();
        char push(char);
        char pop();
        char peek();
};

//Method to check if the stack is empty
bool stack :: isempty(){
    return top==nullptr;
}

//Method to insert element charo the stack
char stack :: push(char element){
    struct node* newnode =(struct node*)malloc(sizeof(struct node));
    newnode->data=element;
    newnode->next=top;
    if(isempty()){
        newnode->prev = nullptr;
        top = newnode;
    } else {
        newnode->prev = top;
        top->next = newnode;
        top = newnode;
    }
    return '1';
}

//Method to delete the topmost element of the stack
char stack :: pop(){
    struct node* temp=top;
    if(isempty()){
        printf("Stack Underflow\n");
        return '-';
    }
    else{
        char del_val = temp->data;
        if (temp->prev != nullptr) {
            top = temp->prev;
            top->next = nullptr;
        } else {
            top = nullptr;
        }
        free(temp);
        return del_val;
    }
}

//Method to display the topmost element in stack
char stack :: peek(){
    if(isempty()){
        printf("Stack Empty\n");
        return '-';
    }
    else{
        return top->data;
    }
}

//Header file to implement Queue ADT using doubly linked list

class queue{
    private:
        struct node{
            struct node* prev;
            char data;
            struct node* next;
        };

        struct node* front;
        struct node* rear;

    public:
        queue(){
            front = nullptr;
            rear =  nullptr;
        }

        bool isempty();
        char enqueue(char);
        char dequeue();
        char peek();
};

//Method to check if the queue is empty
bool queue :: isempty(){
    return front==nullptr;
}

//Method to insert an element charo the queue. Time Complexity O(1).
char queue :: enqueue(char num){
    struct node* newnode=(struct node*)malloc(sizeof(struct node));
    newnode->data=num;
    newnode->next=nullptr;
    if(isempty()){
        rear=newnode;
        front=newnode;
    }
    else{
        rear->next=newnode;
        newnode->prev=rear;
        rear=newnode;
    }
    rear->next=front;
    front->prev=rear;
    return 1;
}

//Method to delete an element from the queue. Time Complexity O(1).
char queue :: dequeue(){
    if(isempty()){
        printf("Empty Queue!");
        return -1;
    }
    else{
        char del_val=front->data;
        if(front==rear){
            front=nullptr;
            rear=nullptr;
        }
        else{
            front=front->next;
            front->prev=nullptr;
        }
        return del_val;
    }
}

//Method to view the front element of the queue. Time Complexity O(1).
char queue :: peek(){
    if (isempty()){
        printf("Queue is Empty!");
        return -1;
    }
    else{
        return front->data;
    }
}

