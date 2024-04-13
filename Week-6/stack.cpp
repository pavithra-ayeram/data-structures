//Program to implement stack ADT using arrays
#include <stdio.h>
#include <stdlib.h>
#define MAX 5    

class stack{
    private:
        char arr[MAX];
        int top;

    public:
        stack(){
            top=-1;
        }

        bool isempty();
        bool isfull();
        char push(char);
        char pop();
        char peek();
        void display();
};

bool stack :: isempty(){
    return top==-1;
}

bool stack :: isfull(){
    return top==MAX-1;
}

//Method to insert element in stack
char stack :: push(char element){
    char j;
    if(isfull()){
        printf("\nStack Overflow!");
        j='-';
        return j;
    }
    else{
        arr[++top]=element;
        j='1';
        return j;
    }
}

//Method to delete the top element in stack
char stack :: pop(){
    char j;
    if(isempty()){
        printf("\nStack is empty");
        j='-';
        return j;
    }
    else{
        char del_val = arr[top];
        arr[top]='0';
        top-=1;
        return del_val;
    }
}

//Method to display the topmost element of stack
char stack :: peek(){
    char j;
    if(isempty()){
        printf("\nStack is empty!");
        j='-';
        return j;
    }
    else{
        return arr[top];
    }
}

//Method to display the elements in stack
void stack :: display(){
    if(isempty()){
        printf("\nStack is empty");
    }
    else{
        printf("\nStack elements are: ");
        for(int i=0; i<=top; i++){
            printf("%c ", arr[i]);
        }
        printf("\n");
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
                printf("Enter element to be inserted: ");
                scanf(" %c", &element);
                i=s.push(element);

                if(i=='-'){
                    printf("\nInsertion failed!");
                }
                else{
                    printf("\nElement inserted successfully!");
                }
                break;
            
            case 2:
                i = s.pop();
                
                if(i=='-'){
                    printf("\nDeletion failed!");
                }
                else{
                    printf("\nPopped element is %c", i);
                }
                break;
            
            case 3:
                i=s.peek();

                if(i=='-'){
                    printf("\nCannot be displayed!");
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