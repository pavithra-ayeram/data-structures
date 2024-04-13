//Program to implement Queue ADT using doubly linked list

#include <stdio.h>
#include <stdlib.h>

class queue{
    private:
        struct node{
            struct node* prev;
            int data;
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
        int enqueue(int);
        int dequeue();
        int peek();
};

//Method to check if the queue is empty
bool queue :: isempty(){
    return front==nullptr;
}

//Method to insert an element into the queue. Time Complexity O(1).
int queue :: enqueue(int num){
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
int queue :: dequeue(){
    if(isempty()){
        printf("Empty Queue!");
        return -1;
    }
    else{
        int del_val=front->data;
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
int queue :: peek(){
    if (isempty()){
        printf("Queue is Empty!");
        return -1;
    }
    else{
        return front->data;
    }
}

int main(){
    queue q;
    int choice, num, i;

    while(1){
        printf("\n\nMenu:\n1.Enqueue\n2.Dequeue\n3.Peek\n4.Exit\nEnter your choice: ");
        scanf("%d", &choice);

        switch(choice){

            case 1:
                printf("Enter a number: ");
                scanf("%d", &num);
                q.enqueue(num);
                break;
            
            case 2:
                printf("%d", q.dequeue());
                break;
            
            case 3:
                printf("%d", q.peek());
                break;
            
            case 4:
                exit(0);
                break;
            
            default:
                printf("Invalid Choice!");
                break;
        }
    }
    return 0;
}