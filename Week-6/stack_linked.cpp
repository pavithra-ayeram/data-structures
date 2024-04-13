//Program to implement stack ADT using linked list
#include <stdio.h>
#include <stdlib.h>

class stack{
    private:
        struct node{
            char data;
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
bool stack :: isempty(){
    return top==nullptr;
}

//Method to insert element into the stack
char stack :: push(char element){
    struct node* newnode =(struct node*)malloc(sizeof(struct node));
    newnode->data=element;
    newnode->next=top;
    top=newnode;
    char j='1';
    return j;
}

//Method to delete the topmost element of the stack
char stack :: pop(){
    struct node* temp=top;
    if(isempty()){
        printf("Stack Underflow\n");
        char j='-';
        return j;
    }
    else{
        top=top->next;
        char del_val=temp->data;
        free(temp);
        return del_val;
    }
}

//Method to display the topmost element in stack
char stack :: peek(){
    struct node* temp=top;
    char j;
    if(isempty()){
        printf("Stack Empty\n");
        j='-';
        return j;
    }
    else{
        return temp->data;
    }
}

//Method to display the stack
void stack :: display(){
    struct node *temp=top;
    if(isempty()){
        printf("\nStack empty!");
    }
    else{
        printf("\nStack elements are: ");
        while(temp!=nullptr){
            printf("%c ",temp->data);
            temp=temp->next;
        }
    }
}

int main(){
    stack s;
    int choice;
    char element, i;

    while(1){
        printf("\nMENU\n1. Push\n2. Pop\n3. Peek\n4. Display\n5. Exit\nEnter your choice: ");
        scanf("%d", &choice);

        switch(choice){
            case 1:
                printf("\nEnter the element to be inserted: ");
                scanf(" %c", &element);

                i=s.push(element);
                if(i=='-'){
                    printf("\nInsertion failed!");    
                }
                else{
                    printf("\nInserted successfully!");
                }
                break;
            
            case 2:
                i=s.pop();

                if(i=='-'){
                    printf("\nDeletion Failed!");
                }
                else{
                    printf("\n%c was deleted successfully.", i);
                }
                break;
            
            case 3:
                i=s.peek();
                if(i=='-'){
                    printf("\nCannot be displayed.");
                }
                else{
                    printf("\n%c is the topmost element!", i);
                }
                break;
            
            case 4:
                s.display();
                break;

            case 5:
                exit(0);
            
            default:
                printf("Invalid Choice!");
                break;
        }
    }
    return 0;
}

