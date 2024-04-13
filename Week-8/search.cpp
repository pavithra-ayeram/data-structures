//Program to implement the search operation that returns the previous smaller and next larger element using binary search tree
#include <stdio.h>
#include <stdlib.h>
#include "search.h" 

int main() {
    tree t;
    int choice, num;
	int prev_smaller, next_bigger;
	
	while(1){
		printf("\nMENU: \n1. Insert\n2. Search\n3. Exit\nEnter your choice: ");
		scanf("%d", &choice);
		t.head=t.get_root();

		switch(choice){
			case 1:
				printf("Enter the element to be inserted: ");
				scanf("%d", &num);
				if(t.insert(t.head, num)){
					printf("Insertion Successfull! \n");
				}
				else{
					printf("Insertion failed!");
				}
				break;
			
			case 2:
				printf("\nEnter the element to the searched: ");
				scanf("%d", &num);

				t.found=t.search(t.head,num);

				if(t.found != nullptr) {
					int prev_smaller = -1;
					int next_bigger = -1;

					// Find previous smaller element
					t.prev = t.found->parent;
					while (t.prev != nullptr) {
						if (t.prev->key < num) {
							prev_smaller = t.prev->key;
							break;
						}
						t.prev = t.prev->parent;
					}

					// Find next bigger element
					t.next = t.found->right;
					while (t.next != nullptr) {
						if (t.next->key > num) {
							next_bigger = t.next->key;
							break;
						}
						t.next = t.next->left;
					}
					printf("%d is present, the previous smaller element is %d, and the next greater element is %d.\n", num, prev_smaller, next_bigger);
    			} 
				else {
        			printf("%d is not present in the tree.\n", num);
    			}
				break;
			
			case 3:
				exit(0);
				break;

			default:
				printf("\nInvalid Choice!");
				break;
		}
	}
	return 0;
}