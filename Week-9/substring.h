//Program to implement list ADT operations in doubly linked list
#include <stdio.h>
#include <stdlib.h>

class linkedlist{
    private:
        struct node{
            struct node* prev;
            char data;
            struct node* next;
        };
    
    public:
        struct node* head;
        struct node* first_index;
        struct node* last_index;
        
        linkedlist(){
            head = nullptr;
            first_index=head;
            last_index=first_index;
        }

        char insert(char);
        int check(int);
        void display();
};

//Method to insert an element at the end of the list. Time Complexity O(n)
char linkedlist :: insert(char num){
    struct node* newnode=(struct node*)malloc(sizeof(struct node));
    newnode->data=num;
    newnode->next=nullptr;
    if(head==nullptr){
		head=newnode;
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
    return'1';
}

//Method to check for unique substrings in the list. Time Complexity O(n)
int linkedlist :: check(int n){
    int count = 0;
    if (head == nullptr) {
        printf("Empty list!\n");
        return 0;
    }

    printf("Checking substrings of length %d\n", n);
    printf("The unique substrings are: ");

    first_index = head;
    
    while(first_index!=nullptr){
        last_index=first_index;
        for(int i=1; i<n && last_index!=nullptr; i++){
            last_index=last_index->next;
        }
        if(last_index==nullptr){
            break;
        }

        bool unique = true;
        bool seen[26] = { false }; 

        struct node* temp1 = first_index;
        while(temp1 != last_index->next){
            if(!seen[(int(temp1->data)-97)]){
                seen[(int(temp1->data)-97)] = true;
            }
            else{
                unique = false;
                break;
            }
            temp1 = temp1->next;
        }

        if(unique){
            count++;
            struct node* temp = first_index;
            printf("\"");
            while(temp != last_index->next){
                printf("%c", temp->data);
                temp = temp->next;
            }
            printf("\"");
            printf("  ");
        }

        first_index = first_index->next;
    }

    printf("\nTotal unique substrings: %d\n", count);

    return count;
}

//Method to display the list. Time Complexity O(n)
void linkedlist::display() {
    struct node* temp = head;
    
    if (temp == nullptr) {
        printf("Empty list!\n");
    } else {        
        while (temp != nullptr) {
            printf("%c ", temp->data);
            temp = temp->next;
        }
        
        printf("\n");
    }
}