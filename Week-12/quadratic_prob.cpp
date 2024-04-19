//Program to implement Hash ADT with Quadratic Probing.
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
      bool insert(int);
      bool search(int);
      bool remove(int);
      void display();
};

//Hash function. Time Complexity O(1).
int hash :: hash_fn(int key) {
    return key % SIZE; 
}

//Method to insert an element into the hash table. Time Complexity O(n).
bool hash :: insert(int key) {
    int index = hash_fn(key);
    	bool tableFull = true;
    for (int i = 0; i < SIZE; i++) {
        if (table[i] == -1) {
            tableFull = false;
            break;
        }
    }

	if (tableFull) {
        printf("Hash table is full.\n");
        return false;
    }
    int i=1;
    while (table[index] != -1) {
        index = (index + i * i) % SIZE; 
        i++;
    }
    table[index] = key;
}

//Method to search for an element in the hash table. Time Complexity O(n).
bool hash :: search(int key) {
    int index = hash_fn(key);
    int i = 1;
    while (table[index] != key) {
        if (table[index] == -1 || i>=SIZE) {
            return false; 
        }
        index = (index + i * i) % SIZE; 
        i++;
    }
    return true;
}

//Method to delete an element from the hash table. Time Complexity O(n).
bool hash::remove(int key) {
    int index = hash_fn(key);
    int i = 1;
    while (table[index] != key) {
        if (table[index] == -1 || i>=SIZE) {
            printf("Element not found.\n");
            return false; 
        }
        index = (index + i * i) % SIZE;
        i++;
    }
    table[index] = -1;
    return true;
}


//Method to display the hash table. Time Complexity O(n).
void hash :: display() {
    printf("Hash Table: ");
    for (int i = 0; i < SIZE; i++) {
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
    int choice, key;

    while (true) {
        printf("\nMENU:\n1. Insert\n2. Delete\n3. Search\n4. Display\n5. Exit\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice){

            case 1:
                printf("Enter key to insert: ");
                scanf("%d", &key);
                if(h.insert(key)){
					printf("Element inserted successfully!\n");
				}
				else{
					printf("Insertion Failed!");
				}
                break;

            case 2:
                printf("Enter key to delete: ");
                scanf("%d", &key);
                if (h.remove(key)) {
                    printf("Element deleted successfully!\n");
                } 
                else {
                    printf("Deletion failed!\n");
                }
                break;

            case 3:
                printf("Enter key to search: ");
                scanf("%d", &key);
                if (h.search(key)) {
                    printf("Element found in the hash table.\n");
                } 
                else {
                    printf("Element not found in the hash table.\n");
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

