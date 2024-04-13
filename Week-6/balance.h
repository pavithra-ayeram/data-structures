//Header file to check if the given string is balance or not using stack ADT
#include <stdio.h>
#include <stdlib.h>

class stack{
  	private:
    	struct node{
      		int data;
      		struct node* next;
    	};

    	struct node* top;

	public:
    	stack(){
      		top=nullptr;
    	}

		bool isempty();
		char push(char);
		char pop();
		char peek();
		void display();
};

//Method to check if the stack is empty
bool stack::isempty() {
	return top==nullptr;
}

//Method to insert an element into the stack
char stack :: push(char element){
	struct node* newnode=(struct node*)malloc(sizeof(struct node));
	newnode->data=element;
	newnode->next=top;
	top=newnode;
	return '*';
}

//Method to delete the topmost element of the stack
char stack :: pop(){
	struct node* temp=top;
	if(isempty()){
		printf("Stack Underflow\n");
		return '-';
	}
	else{
		top=top->next;
		char del_val=temp->data;
		return '*';
	}
}

//Method to view the topmost element of the stack
char stack :: peek(){
	struct node* temp=top;
	if(isempty()){
		printf("Stack Underflow!\n");
		return '-';
	}
	else{
		return temp->data;
	}
}

//Method to display the stack
void stack :: display(){
	struct node* temp=top;
	if(isempty()) {
		printf("Stack Undeflow!\n");
	}
	else{
		printf("Stack elements are: ");
		while(temp!=nullptr){
			printf(" %c ", temp->data);
			temp=temp->next;
		}
	}
}