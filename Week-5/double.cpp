//Program to implement list ADT operations in doubly linked list
#include <stdio.h>
#include <Stdlib.h>

class linkedlist{
    private:
        struct node{
            struct node* prev;
            int data;
            struct node* next;
        };
    
    public:
        struct node* head;
        linkedlist(){
            head = nullptr;
        }
        int insert_beginning(int);
        int insert_position(int, int);
        int insert_end(int);
        int delete_beginning();
        int delete_position(int);
        int delete_end();
        int search(int);
        void display();
};

//Method to insert element at beginning. Time Complexity O(1)
int linkedlist :: insert_beginning(int num){
    struct node* newnode = (struct node*)malloc(sizeof(struct node));
    newnode->data=num;
    newnode->prev=nullptr;
    if(head==nullptr){
        head=newnode;
        newnode->next=nullptr;
    }
    else{
        head->prev=newnode;
        newnode->next=head;
        head=newnode;
    }
    return 1;
}

//Method to insert an element in a specific position. Time Complexity O(n)
int linkedlist :: insert_position(int num, int pos){
    struct node* newnode = (struct node *)malloc(sizeof(struct node));
    newnode->data=num;
    if(pos==1){
        insert_beginning(num);
    }
    else{
        struct node* temp = head;
        for(int i=1; i<pos-1 && temp!=nullptr; i++){
            temp=temp->next;
        }
        if(temp==nullptr){
            printf("Position out of bounds.");
            return -1;
        }
        newnode->next=temp->next;
        newnode->prev=temp;
        temp->next=newnode;
    }
    return 1;
}

//Method to insert an element at the end of the list. Time Complexity O(n)
int linkedlist :: insert_end(int num){
    struct node* newnode=(struct node*)malloc(sizeof(struct node));
    newnode->data=num;
    newnode->next=nullptr;
    if(head==nullptr){
        insert_beginning(num);
        return 1;
    }
    else{
        struct node* temp=head;
        while(temp->next!=nullptr){
            temp=temp->next;
        }
        newnode->prev=temp;
        temp->next=newnode;
        head->prev=temp;
    }
    return 1;
}

//Method to delete element at the beginning of the list. Time Complexity O(1)
int linkedlist :: delete_beginning(){
    struct node* temp=head;
    if(head==nullptr){
        printf("Empty list!");
        return -1;
    }
    else{
        head=temp->next;
        head->prev=nullptr;
        int del_val=temp->data;
        free(temp);
        return del_val;
    }
}

// Method to delete element at a specific position. Time Complexity O(n)
int linkedlist::delete_position(int pos) {
    if (head == nullptr) {
        printf("Empty List!\n");
        return -1;  // Return -1 to indicate an error or special case
    } 

    if (pos == 1) {
        return delete_beginning();
    } 

    struct node* temp = head;

    for (int i = 1; i < pos && temp != nullptr; i++) {
        temp = temp->next;
    }

    if (temp == nullptr) {
        printf("Position out of bounds!\n");
        return -1;  // Return -1 to indicate an error or special case
    }

    int del_val = temp->data;

    if (temp->prev != nullptr) {
        temp->prev->next = temp->next;
    } else {
        head = temp->next;
    }

    if (temp->next != nullptr) {
        temp->next->prev = temp->prev;
    }

    free(temp);
    return del_val;
}



//Method to delete element at the end of the list. Time Complexity O(n)
int linkedlist::delete_end(){
    struct node*  temp=head;
    if(head==nullptr){
        printf("Empty List!");
        return -1;
    }
    else{
        if (temp->next == nullptr) {
            int del_val = temp->data;
            free(temp);
            head = nullptr;
            return del_val;
        }
        while(temp->next!=nullptr) {
            temp = temp->next;
        }
        int del_val = temp->data;
        temp->prev->next=nullptr;  

        free(temp);
        return del_val;
    } 
}

//Method to search for an element in the list. Time Complexity O(n)
int linkedlist :: search(int num){
    struct node* temp=head;
    int count=0;
    while(temp != nullptr){
        if(temp->data==num){
            return count+1;
        }
        temp=temp->next;
        count++;
    }
    return -1;
}

//Method to display the list. Time Complexity O(n)
void linkedlist::display() {
    struct node* temp = head;
    
    if (temp == nullptr) {
        printf("Empty list!\n");
    } else {        
        while (temp != nullptr) {
            printf("%d ", temp->data);
            temp = temp->next;
        }
        
        printf("\n");
    }
}


int main(){
    linkedlist dll;
    int choice, num, pos, i;

    while(1){
        printf("\nMENU\n1. Insert at beginning\n2. Insert at position\n3. Insert at end\n4. Delete at beginning\n5. Delete at position\n6. Delete at end\n7. Search\n8. Display\n9. Exit\nEnter your choice: ");
        scanf("%d", &choice);

        switch(choice){

            case 1:
                printf("Enter the element you want to insert: ");
                scanf("%d", &num);
                i=dll.insert_beginning(num);

                if(i==-1){
                    printf("Insertion failed!");
                }
                else{
                    printf("The element %d was inserted successfully.", num);
                }
                break;
            
            case 2:
                printf("Enter the element to be inserted: ");
                scanf("%d", &num);
                printf("Enter the position to be inserted in: ");
                scanf("%d", &pos);
                i=dll.insert_position(num, pos);

                if(i==-1){
                    printf("Insertion failed!");
                }
                else{
                    printf("The element %d was inserted at position %d successfully.", num, pos);
                }
                break;
            
            case 3:
                printf("Enter the element you want to insert: ");
                scanf("%d", &num);
                i=dll.insert_end(num);

                if(i==-1){
                    printf("Insertion failed!");
                }
                else{
                    printf("The element %d was inserted successfully.", num);
                }
                break;

            case 4:
                i=dll.delete_beginning();
                if(i==-1){
                    printf("Deletion failed!");
                }
                else{
                    printf("The element %d was deleted successfully.", i);
                }
                break;

            case 5:
                printf("Enter the position of the element you want to delete: ");
                scanf("%d", &pos);
                i=dll.delete_position(pos);

                if(i==-1){
                    printf("Deletion failed!");
                }
                else{
                    printf("The element %d at position %d was deleted successfully.", i, pos);
                }
                break;

            case 6:
                i=dll.delete_end();

                if(i==-1){
                    printf("Deletion failed!");
                }
                else{
                    printf("The element %d was deleted successfully.", i);
                }
                break;

            case 7:
                printf("Enter the element you want to search: ");
                scanf("%d", &num);
                i=dll.search(num);

                if(i==-1){
                    printf("Element not found!");
                }
                else{
                    printf("The element %d was found at position %d.", num, i);
                }
                break;

            case 8:
                printf("The list is: ");
                dll.display();
                break;
            
            case 9:
                exit(0);
                break;
            
            default:
                printf("Invalid Choice!");
                break;
        }
    }
    return 0;
}