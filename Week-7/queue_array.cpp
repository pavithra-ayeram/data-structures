//Program to implement Queue ADT using array

#include <stdio.h>
#include <stdlib.h>
#define SIZE 5

class queue{

    private:
        int arr[SIZE];
        int front;
        int rear;
    
    public:
        queue(){
            front = -1;
            rear = -1;
        }
        int isfull();
        int isempty();
        int enqueue(int);
        int dequeue();
        int peek();
};

//Method to check if the queue is full
int queue :: isfull(){
    return (rear == SIZE - 1);
}

//Method to check if the queue is empty
int queue :: isempty(){
    return (front == -1 && rear == -1);
}

//Method to insert an element into queue. Time Complexity O(1)
int queue :: enqueue(int n){
    if(isfull()){
        printf("Queue is full!");
        return 0;
    }
    else{
        if(isempty()) {
            front = rear = 0;
        }
        else {
            rear++;
        }
        arr[rear] = n;
        return 1;
    }
}

//Method to delete an element from queue. Time Complexity O(1)
int queue :: dequeue(){
    if(isempty()){
        printf("Queue is empty!");
        return -1;
    }
    else{
        int del_val = arr[front];
        if(front == rear){
            front = rear = -1;
        }
        else{
            front++;
        }
        return del_val;
    }
}

//Method to view the front element. Time Complexity O(1)
int queue :: peek(){
    if(isempty()){
        printf("Queue is empty!");
        return -1;
    }
    else{
        return arr[front];
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
