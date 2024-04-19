#include <stdio.h>
#include <stdlib.h>
#define SIZE 10

class hash {
	private:
		int table[SIZE];

	public:
		hash() {
			for (int i = 0; i < SIZE; i++) {
				table[i] = -1; 
			}
		}

		int hash_fn(int);
		int insert(int);
		bool search(int);
		int remove(int);
		void display();		
};

// Hash function. Time complexity O(1).
int hash :: hash_fn(int value) {
	return value % SIZE; 
}

//Method to insert value into the hash table. Time complexity O(n).
int hash :: insert(int value) {
	int index = hash_fn(value);
	bool tableFull = true;
    for (int i = 0; i < SIZE; ++i) {
        if (table[i] == -1) {
            tableFull = false;
            break;
        }
    }

	if (tableFull) {
        printf("Hash table is full.\n");
        return 0;
    }

	if(table[index] != -1) { 
		++index;
		while(table[index] != -1 && table[index] != SIZE-1) {
			++index;
			if(index >= SIZE)
				index=0;
		}
	}
	table[index]=value;
	return 1;
}

//Method to search for value in the hash table. Time complexity O(n).
bool hash :: search(int value) {
	int index = hash_fn(value);
	while (table[index] != -1) {
		if (table[index] == value) {
			return true;
		}
		index = (index + 1) % SIZE; 
	}
	return false;
}

//Method to delete value from the hash table. Time complexity O(n).
int hash :: remove(int value) {
	int index = hash_fn(value);
	while (table[index] != -1) {
		if (table[index] == value) {
			table[index] = -1; 
			return 1;
		}
		index = (index + 1); 
	}
	return 0;
}

//Method to display the contents of the hash table. Time complexity O(n).
void hash :: display() {
	printf("Hash Table: ");
	for (int i = 0; i < SIZE; ++i) {
		if (table[i] != -1) {
			printf("%d ", table[i]);
		} else {
			printf("X "); 
		}
	}
	printf("\n");
}

int main() {
    hash h;
    int choice, value;

    while (true) {
        printf("\nMENU:\n1. Insert\n2. Delete\n3. Search\n4. Display\n5. Exit\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice) {

            case 1:
                printf("Enter value to insert: ");
                scanf("%d", &value);
                if(h.insert(value)){
					printf("Elemented inserted successfully!\n");
				}
				else{
					printf("Insertion failed!");
				}
                break;

            case 2:
                printf("Enter value to delete: ");
                scanf("%d", &value);
                if(h.remove(value)){
					printf("Element removed successfully!");
				}
				else{
					printf("Deletion failed!");
				}
                break;

            case 3:
            	printf("Enter value to search: ");
                scanf("%d", &value);
                if (h.search(value)) {
                    printf("Value found in the hash table.\n");
                } else {
                    printf("Value not found in the hash table.\n");
                }
                break;

            case 4:
                h.display();
                break;

            case 5:
                exit(0);

            default:
                printf("Invalid choice!\n");
                break;
        }
    }

    return 0;
}
