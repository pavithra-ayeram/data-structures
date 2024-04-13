//Program to implement round robin scheduling algorithm using circular queue ADT

#include <stdio.h>
#include <stdlib.h>
#include "round_robin.h"

int main(){
	queue q;
	int choice, num, time;
	int fixed_time = 10;

	while(1){
		printf("\n\nMenu:\n1. Insert\n2. Execute\n3. Exit\nEnter your choice: ");
		scanf("%d", &choice);

		switch(choice){
			case 1:
				printf("\nEnter the time to be enqueued: ");
				scanf("%d", &num);
				if(q.enqueue(num)){
					printf("\nInserted Successfully");
				}
				else{
					printf("\nInsertion failed!");
				}
				break;
			
			case 2:
				time=q.peek();
				q.dequeue();
				if((time-fixed_time)<=0){
					printf("\nExecution Completed!");
				}
				else{
					q.enqueue(time - fixed_time);
					printf("\nTime Remaining in Queue: %d", (time - fixed_time));
				}
				break;
			
			case 3:
				exit(0);
				break;
			
			default:
				printf("Invalid Choice!");
				break;
		}
	}
	return 0;
}