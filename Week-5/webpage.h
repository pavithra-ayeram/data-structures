//Header file to implement a browser's front and back functionality using doubly linked lists
#include <stdio.h>
#include <stdlib.h>

class web_page {
	private:
		struct node {
			struct node* prev;
			int data;
			struct node* next;
		};

		struct node* head;
		struct node* current;
        int index;

	public:
		web_page() {
			head = nullptr;
			current = nullptr;
            index = 0;
		}
		int new_page();
		int back();
		int front();
		void display();
};


//Method to add new webpage. Time Complexity O(n)
int web_page :: new_page() {
    struct node* newnode = (struct node*)malloc(sizeof(struct node));
    index++;
    newnode->data = index;

    if (head == nullptr) {
        head = newnode;
        current = newnode;
        newnode->next = nullptr;
        newnode->prev = nullptr;
    } else {
        newnode->next = nullptr;
        newnode->prev = current;
        current->next = newnode;
        current = newnode;
    }

    // Delete nodes after current
    struct node* temp = current->next;
    while (temp != nullptr) {
        struct node* to_delete = temp;
        temp = temp->next;
        free(to_delete);
    }

    return index;
}

//Method to move to the previous webpage. Time Complexity O(1)
int web_page :: back() {
    if (current->prev != nullptr) {
        current = current->prev;
		printf("\nMoved to the back webpage");
		printf("\nCurrent webpage is: %d", current->data);
        index--;
        return 1;
    } else {
        printf("Already at the first webpage.");
        return 0;
    }
}

//Method to move to the next webpage. Time Complexity O(1)
int web_page :: front() {
    if (current->next != nullptr) {
        current = current->next;
		printf("\nMoved to the front webpage");
		printf("\nCurrent webpage is: %d", current->data);
        index++;
        return 1;
    } else {
        printf("Already at the last webpage.");
        return 0;
    }
}

//Method to display the list of webpages. Time Complexity O(n)
void web_page :: display() {
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
