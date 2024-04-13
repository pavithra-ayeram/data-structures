#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "substring.h"

int main(){
	linkedlist l;
	int choice, i;
	char arr[20];
    
	while(1){
		printf("\nMENU\n1. Insert\n2. Check\n3. Display\n4. Exit\nEnter your choice: ");
		scanf("%d", &choice);

		switch(choice){
			case 1:
				printf("Enter the elements of the string: ");
				scanf(" %s", arr);
				for (i=0; arr[i]!='\0'; i++) {
					l.insert(arr[i]);
				}
				break;

			case 2:
				printf("Enter the number of letters in the substring: ");
				scanf("%d", &i);
				l.check(i);
				break;
			
			case 3:
				l.display();
				break;
			
			case 4:
				exit(0);
				break;
			
			default:
				printf("Invalid Choice!");
				break;
		}
	}
}