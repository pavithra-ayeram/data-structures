//Program to implement postfix conversion and evaluation using stack ADT with linked list
#include <stdio.h>
#include <stdlib.h>
#include "stack_linked.h"

int main(){
	stack s;
	int choice;
	char result;

	while(1){
		printf("\nMENU\n1. Get Infix expression\n2. Convert to Postfix\n3. Evaluate Postfix expression\n4. Exit\nEnter your choice: ");
		scanf( "%d", &choice);
		switch (choice) {
			case 1 :
				printf("Enter your infix expression: ");
				scanf(" %s", s.infix_exp);
				printf("%s", s.infix_exp);
				break;
			
			case 2:
				if(s.conversion(s.infix_exp)){
					printf("Postfix Expression is: %s\n", s.postfix_exp);
				}
				else{
					printf("Conversion Failed!");
				}
				break;
			
			case 3:
				result=s.evaluation(s.postfix_exp);
				printf("\nResult = %d\n",result);
				break;
			
			case 4:
				exit(0);

			default:
				printf("Invalid Choice! Enter a valid choice: ");
				break;
		}
	}
	return 0;
}