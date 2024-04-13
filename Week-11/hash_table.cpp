//Program to implement hash table using arrays
#include <stdio.h>
#include <stdlib.h>
#define SIZE 10

class hash{
	private:
		struct node{
			int value;
			struct node* next;
		};
		struct node* hash_table[SIZE];

	public:
		hash(){
			for(int i=0; i<SIZE; i++){
				hash_table[i]=nullptr;
			}
		}

		int hash_function(int);
		int insert(int);
		int remove(int);
		int search(int);
};

//Method to define the hash function of the hash table. Time Complexity O(1).
int hash :: hash_function(int ele){
	return (ele%SIZE);
}

//Method to insert an element into the hash table. Time Complexity O(n).
int hash :: insert(int data){
	int index=hash_function(data);
	struct node* newnode=(struct node*)malloc(sizeof(struct node));
	if(newnode==nullptr){
		return 0;
	}
	newnode->value=data;
	newnode->next=nullptr;

	if(hash_table[index]==nullptr){
		hash_table[index]=newnode;
	}
	else {
		struct node* temp = hash_table[index];
		while (temp->next != nullptr) {
			temp = temp->next;
		}
		temp->next = newnode;

	}
	return 1;
}

//Method to delete an element from the hash table. Time Complexity O(n).
int hash :: remove(int data){
	int index=hash_function(data);
	struct node* temp=hash_table[index];
	struct node* prev=nullptr;

	while(temp!=nullptr && temp->value!=data){                                                                    
		prev=temp;
		temp=temp->next;
	}

	if(temp!=nullptr){
		if(prev!=nullptr){
			prev->next=temp->next;
		}
		else{
			hash_table[index]=temp->next;
		}
		free(temp);
		return 1;
	}
	return -1; 
}

//Method to search for an element in the hash table. Time Complexity O(n).
int hash :: search(int data){
	int index=hash_function(data);
	struct node* temp=hash_table[index];
	while(temp!=nullptr){
		if(temp->value==data){
			return 1;
		}
		temp=temp->next;
	}
	return -1;
}


int main(){
	hash h;
	int choice, i;

	while(1){
		 printf("\nMenu:\n1. Insertion\n2. Deletion\n3. Search\n4. Exit\nEnter your choice: ");
		 scanf("%d", &choice);

		 switch(choice){
			case 1:
				printf("Enter a number to be inserted: ");
				scanf("%d", &i);
				if(h.insert(i)==0){
					printf("Insertion failed.\n");
				}
				break;

			case 2:
				printf("Number to be deleted: ");
				scanf("%d", &i);
				if(h.remove(i)==-1){
					printf("Element not found.\n");
				}else{
					printf("Deleted successfully.\n");
				}
				break;
			
			case 3:
				printf("Enter element to be searched: ");
				scanf("%d", &i);
				if(h.search(i)==-1){
					printf("Element %d is not in the hash table.\n", i);
				}else{
					printf("Element %d is present.\n", i);
				}
				break;

			case 4:
				return 0;

			default :
				printf("Invalid Choice!\n");
		}
	}
}
