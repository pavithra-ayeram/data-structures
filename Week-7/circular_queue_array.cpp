//Program to implement Circular Queue ADT using array

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
			front=-1;
			rear=-1;
		}

		bool isempty();
		bool isfull();
		int enqueue(int);
		int dequeue();
		int peek();
};

//Method to check if the queue is empty
bool queue :: isempty(){
	return (rear==-1 && front==-1);
}

//Method to check if the queue is full
bool queue :: isfull(){
	return ((rear+1)%SIZE==front);
}

//Method to insert an element to the queue. Time Complexity O(1).
int queue :: enqueue(int num){
	if(isempty()){
		front++;
		rear++;
		arr[rear]=num;
		return 1;
	}
	else if(isfull()){
		printf("Queue is full!");
		return -1;
	}
	else{
		rear=(rear+1)%SIZE;
		arr[rear]=num;
		return 1;
	}
}

//Method to delete an element from the queue. Time Complexity O(1).
int queue :: dequeue(){
	if(isempty()){
		printf("Queue is empty!");
		return -1;
	}
	else{
		int del_val=arr[front];
		if(front == rear){
			front = -1;
			rear = -1;
		}
		else{
			front=(front+1)%SIZE;
		}		
		return del_val;
	}
}

//Method to view the front element of the queue. Time Complexity O(1).
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
				printf("Enter a number to enqueue: ");
				scanf("%d", &num);
				q.enqueue(num);
				break;

			case 2:
				num = q.dequeue();
				if(num != -1)
					printf("The deleted value is %d\n", num);
				else
					printf("Deletion Failed\n");
				break;
			
			case 3:
				num=q.peek();
				if(num!=-1){
					printf("The front element is %d", num);
				}
				else{
					printf("No element to show!");
				}
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