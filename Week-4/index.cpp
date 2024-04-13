//Program to implement insertion and merging using singly linked lists
#include <stdio.h>
#include <stdlib.h>
#include "linkedlist.h"

int main(){
  linkedlist l1,l2,l3;
  int choice, num, i, k;

  while(1){
    printf("\n\nMENU\n1. Insert List 1\n2. Insert List 2\n3. Merge into List 3\n4. Display\n5. Exit\nEnter your choice: ");
    scanf("%d", &choice);

    switch(choice){
      
      case 1:
        printf("Enter the number of elements in list 1: ");
        scanf("%d", &i);
        printf("Enter the elements of the list: ");
        for(int j=0; j<i; j++){
          scanf("%d", &num);
          l1.insert_ascending(num);
        }
		printf("\nElements inserted successfully!");
        break;
      
      case 2:
        printf("Enter the number of elements in list 2: ");
        scanf("%d", &i);
        printf("Enter the elements of the list: ");
        for(int j=0; j<i; j++){
          scanf("%d", &num);
          l2.insert_ascending(num);
        }
		printf("Elements inserted successfully!");
        break;

      case 3:
        l3.merge(l1, l2, l3);
		printf("\nThe lists were merged successfully");
        break;
      
      case 4:
        printf("Enter the list you want to print: ");
        scanf("%d", &num);

        if (num == 1) {
            l1.display();
        } 
        else if (num == 2) {
            l2.display();
        } 
        else if (num == 3) {
            l3.display();
        } 
        else {
            printf("Enter valid number!");
        }
        break;
      
      case 5:
        exit(0);
        break;
      
      default:
        printf("\nInvalid choice!");
        break;
    }
  }
  return 0;
}