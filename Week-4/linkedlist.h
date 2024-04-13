//Header file to implement list ADT using singly linked list
#include <stdio.h>
#include <stdlib.h>

class linkedlist{
  	private:
    	struct node{
			int data;
			struct node* address;
		};
		node* get_head();
	public:
		struct node * head;
		linkedlist(){
			head=nullptr;
		}
		int insert_ascending(int);
		int merge(linkedlist, linkedlist, linkedlist&);
		void display();
};

//Method to get the address of head value of the list
linkedlist :: node* linkedlist::get_head(){
	return head;
}

//Method to insert a number in ascending order
int linkedlist::insert_ascending(int num) {
    struct node* newnode = (struct node*)malloc(sizeof(struct node));
    newnode->data = num;
    newnode->address = nullptr;

    if (head == nullptr || num < head->data) {
        newnode->address = head;
        head = newnode;
    } else {
        struct node* temp = head;

        while (temp->address != nullptr && num > temp->address->data) {
            temp = temp->address;
        }

        newnode->address = temp->address;
        temp->address = newnode;
    }

    return 1;
}

//Method to merge two lists in ascending order
int linkedlist::merge(linkedlist l1, linkedlist l2, linkedlist& l3){
    struct node* temp1 = l1.get_head();
    struct node* temp2 = l2.get_head();

    while (temp1 != nullptr || temp2 != nullptr) {
        if (temp1 != nullptr && (temp2 == nullptr || temp1->data <= temp2->data)) {
            l3.insert_ascending(temp1->data);
            temp1 = temp1->address;
        } else {
            l3.insert_ascending(temp2->data);
            temp2 = temp2->address;
        }
    }

    return 1;
}

//Method to display the list
void linkedlist :: display(){
	struct node *temp = head;
    if(head==NULL){
        printf("List is empty!");
    }
    else{
	    while(temp!=nullptr){
		    printf("%d ", temp->data);
		    temp=temp->address;
	    }
    }
}