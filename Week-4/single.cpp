//Program to implement list ADT operations in singly linked list
#include <stdio.h>
#include <stdlib.h>

class linkedlist{
	private:
		struct node{
			int data;
			struct node* address;
		};

		struct node* head;

	public:
		linkedlist(){
			head=nullptr;
		}
		int insert_beg(int);
		int insert_pos(int, int);
		int insert_end(int);
		int delete_beg();
		int delete_pos(int);
		int delete_end();
		int search(int);
		int display();
		void display_reverse();
		void reverse(struct node* );
		void reverselink();
};

//Method to insert an element at the beginning. Time complexity O(1)
int linkedlist :: insert_beg(int num){
	struct node* newnode=(struct node*)malloc(sizeof(struct node));
	newnode->data=num;
	newnode->address=head;
	head=newnode;
	return 1;
}

//Method to insert an element at given position. Time complexity O(n)
int linkedlist :: insert_pos(int num, int pos){
	struct node* newnode=(struct node*)malloc(sizeof(struct node));
	newnode->data=num;
	if(head==nullptr){
		return insert_beg(num);
	}
	
	struct node* temp=head;
	
	for(int i=1;i<pos-1 && temp!=nullptr; i++){
		temp=temp->address;
	}

	if(temp==nullptr){
		printf("Position out of bounds.");
		free(newnode);
		return 0;
	}

	newnode->address=temp->address;
	temp->address=newnode;
	return 1;
}

//Method to insert an element at the end. Time complexity O(n)
int linkedlist :: insert_end(int num){
	struct node* newnode=(struct node*)malloc(sizeof(struct node));
	newnode->data=num;
	newnode->address=nullptr;
	if(head==nullptr){
		return insert_beg(num);
	}

	struct node* temp=head;

	while(temp->address!=nullptr){
		temp=temp->address;
	}

	temp->address=newnode;
	return 1;
}

//Method to delete an element at the beginning. Time complexity O(1)
int linkedlist :: delete_beg(){
	if(head==nullptr){
		printf("Empty list!");
		return -1;
	}
	
	struct node* temp=head;
	head=head->address;
	int del_val=temp->data;
	free(temp);
	return del_val;
}

//Method to delete an element at given position. Time complexity O(n)
int linkedlist::delete_pos(int pos) {
    if (head == nullptr) {
        printf("Empty list!");
        return -1;
    }

    struct node* temp = head;

    for (int i = 1; i < pos - 1 && temp != nullptr; i++) {
        temp = temp->address;
    }

    if (temp == nullptr || temp->address == nullptr) {
        printf("Position out of bounds.\n");
        return -1;
    }

    struct node* temp_2 = temp->address;
    int del_val = temp_2->data;
    temp->address = temp_2->address;
    free(temp_2);
    return del_val;
}

//Method to delete an element at the end. Time complexity O(n)
int linkedlist :: delete_end(){
	if(head==nullptr){
		printf("Empty list!");
		return -1;
	}
	struct node* temp=head;

	while(temp->address->address!=nullptr){
		temp=temp->address;
	}

	int del_val=temp->address->data;
	free(temp->address);
	temp->address=nullptr;
	return del_val;
}

//Method to search for an element. Time complexity O(n)
int linkedlist :: search(int num){
	int count=1;
	struct node* temp=head;

	while(temp != nullptr) {
		if(temp->data==num){
			return count;
		}
		count++;
		temp=temp->address;
	}
	return -1;
}

//Method to display the list. Time complexity O(n)
int linkedlist :: display(){
	struct node* temp=head;
	if(head==nullptr){
		printf("Empty list!");
	}
	while(temp!=nullptr){
		printf("%d ", temp->data);
		temp=temp->address;
	}
	return 0;
}

//Method to display the list in reverse. Time complexity O(n)
void linkedlist :: reverse(struct node* temp){
    if (temp == nullptr) {
        return;
    }

    reverse(temp->address);

    printf("%d ", temp->data);
}

void linkedlist :: display_reverse(){
	reverse(head);
	printf("\n");
}

//Method to reverse the link of the list. Time complexity O(n)
void linkedlist :: reverselink() {
    struct node* prev = nullptr;
    struct node* current = head;
    struct node* next = nullptr;

    while (current != nullptr) {
        next = current->address;
        current->address = prev;
        prev = current;
        current = next;
    }

    head = prev;
}

int main(){
	linkedlist ll;
	int choice, num, pos, i;

	while(1){
		printf("\nMENU\n1. Insert at beginning\n2. Insert at position\n3. Insert at end\n4. Delete at beginning\n5. Delete at position\n6. Delete at end\n7. Search\n8. Reverse\n9. Reverse link\n10. Display\n11. Exit");
		printf("\nEnter your choice: ");
		scanf("%d", &choice);

		switch(choice){
			case 1:
				printf("Enter the element to be inserted: ");
				scanf("%d", &num);

				if(ll.insert_beg(num)){
					printf("Element inserted successfully!");
				}
				else{
					printf("Insertion failed!");
				}
				break;

			case 2:
				printf("Enter the element to be inserted: ");
				scanf("%d", &num);
				printf("Enter the position to be inserted in: ");
				scanf("%d", &pos);

				if(ll.insert_pos(num,pos)){
					printf("Element inserted successfully!");
				}
				else{
					printf("Insertion failed!");
				}
				break;

			case 3:
				printf("Enter the element to be inserted: ");
				scanf("%d", &num);

				if(ll.insert_end(num)){
					printf("Element inserted successfully!");
				}
				else{
					printf("Insertion failed!");
				}
				break;

			case 4:
				i=ll.delete_beg();

				if(i!=-1){
					printf("The element %d was deleted successfully!", i);
				}
				else{
					printf("Deletion failed!");
				}
				break;

			case 5:
				printf("Enter the position of the element to be deleted: ");
				scanf("%d", &pos);
				i=ll.delete_pos(pos);

				if(i!=-1){
					printf("The element %d at position %d was deleted successfully!", i, pos);
				}
				else{
					if(i==-1){
						printf("Deletion failed!");
					}
				}
				break;

			case 6:
				i=ll.delete_end();
				if(i!=-1){
					printf("The element %d was deleted successfully!", i);
				}
				else{
					printf("Deletion failed!");
				}
				break;

			case 7:
				printf("Enter element to be searched: ");
				scanf("%d", &num);
				i=ll.search(num);

				if(i==-1){
					printf("Element not found!");
				}
				else{
					printf("Element found at position %d", i);
				}
				break;
			
			case 8:
				printf("The list in reverse is: \n");
				ll.display_reverse();
				break;

			case 9:
				ll.reverselink();
				printf("The list was reversed successfully.");
				break;
							
			case 10:
				printf("The list is: \n");
				ll.display();
				break;
			
			case 11:
				exit(0);
				break;
			
			default:
				printf("Invalid Choice!");
				break;
		}
	}
	return 0;
	
}
