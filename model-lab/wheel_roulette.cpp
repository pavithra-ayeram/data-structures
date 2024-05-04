# include <stdio.h>
# include <signal.h>
# include <stdlib.h>


class list{
	private:
		struct node{
			struct node* prev;
			int data;
			struct node* next;
		};
		struct node* head;
		struct node* tail;
		struct node* current;
	
	public:
		list(){
			head=nullptr;
			tail=nullptr;
			current=nullptr;
		}

		struct node* get_cur();
		int create(int);
		int spin_wheel();
};

list :: node* list :: get_cur(){
	return current;
}

// Function to insert a node at the end of the list
int list :: create(int data) {
    struct node* newnode = (struct node*)malloc(sizeof(struct node));
	newnode->data=data;
	newnode->next=nullptr;
    if (!head) {
        head = newnode;
        tail = newnode;
        head->next = head; 
        head->prev = head; 
        current = head;  
    } 
    else {
        newnode->prev = tail;
        newnode->next = head;
        tail->next = newnode;
        tail = newnode;
        head->prev = tail; 
    }
}

int list :: spin_wheel() {
    if (!head) {
        return 0; 
    } 
	else {
        current = current->next;
        return current->data;
    }
}

volatile int interrupt_received = 0;

void interrupt_handler(int signal){
	interrupt_received = 1;
}

int main(){
	list l;
	int elements, items, number, num, percent;
	int total_number=0;

	printf("Enter the number of elements to be stored in the spin wheel: ");
	scanf("%d", &elements);

	printf("Enter the number of items in the spin wheel: ");
	scanf("%d", &items);

	for (int i=0; i<items; i++){
		printf("Enter the item to be inserted: ");
		scanf("%d", &num);

		printf("Enter the occupancy percentage of %d: ", num);
		scanf("%d", &percent);

		number=(percent*elements)/100;
		total_number+=number;

		if(number<1 || total_number>elements){
			printf("Invalid input!\n");
		}
		else{
			for(int j=0; j<number; j++){
				l.create(num);
			}
		}
	}

	// Set up signal handler for SIGINT
	if (signal(SIGINT, interrupt_handler) == SIG_ERR) {
		perror("Error setting up signal handler");
		exit(EXIT_FAILURE);
	}

    // Ignore SIGINT so that the program doesn't terminate immediately when Ctrl+C is pressed
    if (signal(SIGINT, interrupt_handler) == SIG_ERR) {
        printf("Could not catch SIGINT\n");
        return 1;
    }

	while(!interrupt_received){
		l.spin_wheel();
		printf("Waiting for interrupt...\n");
	}

	printf("%d is the winner", l.get_cur()->data);
	printf("\nInterrupted!\n");

	return 0;
}
