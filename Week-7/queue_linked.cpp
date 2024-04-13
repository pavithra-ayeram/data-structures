//Program to implement Queue ADT using linked lists

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
            rear = nullptr;
        }

        bool isempty();
        int enqueue(int);
        int dequeue();
        int peek();
};

//Method to check if the queue is empty
bool queue :: isempty(){
    return rear==nullptr;
}

//Method to insert an element into the queue. Time Complexity O(1)
int queue :: enqueue(int num){
    struct node* newnode = (struct node*)malloc(sizeof(struct node));
    newnode->data=num;
    newnode->next=nullptr;

    if(isempty()){
        front=rear=newnode;
    }
    else{
        rear->next=newnode;
        newnode->prev=rear;
        rear=newnode;
    }
    return 1;
}

//Method to delete an element from the queue. Time Complexity O(1)
int queue :: dequeue(){
    if(isempty()){
        printf("Queue is empty!");
        return -1;
    }
    else{
        int del_val=front->data;
        front=front->next;
        return del_val;
    }
}


//Method to view the front element of the queue. Time Complexity O(1)
int queue :: peek(){
    if(isempty()){
        printf("Queue is empty!");
        return -1;
    }
    else{
        return front->data;
    }
}

int main(){
    queue q;
    int choice, num;

    while(1){
        printf("\n\nMenu:\n1.Enqueue\n2.Dequeue\n3.Peek\n4.Exit\nEnter your choice: ");
        scanf("%d", &choice);

        switch(choice){

            case 1:
                printf("Enter element to be enqueued: ");
                scanf("%d", &num);
                if(q.enqueue(num)){
                    printf("Element inserted successfully.\n");
                }
                else{
                    printf("Insertion failed!\n");
                }
                break;
            
            case 2:
                num = q.dequeue();
                if(num != -1){
                    printf("Element %d deleted successfully.\n", num);
                }
                else{
                    printf("Deletion failed!\n");
                }
                break;
            
            case 3:
                num = q.peek();
                if(num != -1){
                    printf("Peeked value is %d.\n", num);
                }
                else{
                    printf("Queue is empty.\n");
                }
                break;

            case 4:
                exit(0);
                break;
            
            default:
                printf("Invalid Choice!\n");
        }
    }
    return 0;
}
