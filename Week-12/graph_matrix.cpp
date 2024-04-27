//Program to implement Graph ADT with Adjacency Matrix.
#include <stdio.h>
#include <stdlib.h>
#define MAX_VERTICES 5

//Graph Implementation
class graph {
private:
    int vertices;
    int adj_matrix[MAX_VERTICES][MAX_VERTICES];

public:
    graph() {
        vertices = MAX_VERTICES;
        for (int i = 0; i < vertices; i++) {
            for (int j = 0; j < vertices; j++) {
                adj_matrix[i][j] = 0; // Initializing with 0 instead of -1
            }
        }
    }
    bool insert(int, int);
    bool search(int, int);
    bool remove(int, int);
    void display();
};

// Method to insert an edge into the graph. Time Complexity O(1).
bool graph::insert(int v1, int v2) {
    if (v1 < 0 || v1 >= vertices || v2 < 0 || v2 >= vertices) {
        printf("Invalid vertex indices!\n");
        return false;
    }
    adj_matrix[v1][v2] = 1;
    adj_matrix[v2][v1] = 1;
    return true;
}

// Method to search for an edge in the graph. Time Complexity O(1).
bool graph::search(int v1, int v2) {
    if (v1 < 0 || v1 >= vertices || v2 < 0 || v2 >= vertices) {
        printf("Invalid vertex indices!\n");
        return false;
    }
    return adj_matrix[v1][v2] == 1;
}

// Method to remove an edge from the graph. Time Complexity O(1).
bool graph::remove(int v1, int v2) {
    if (v1 < 0 || v1 >= vertices || v2 < 0 || v2 >= vertices) {
        printf("Invalid vertex indices!\n");
        return false;
    }
    adj_matrix[v1][v2] = 0;
    adj_matrix[v2][v1] = 0; 
    return true;
}

// Method to display the adjacency matrix of the graph. Time Complexity O(n^2).
void graph::display() {
    printf("Adjacency Matrix:\n");
    for (int i = 0; i < vertices; i++) {
        for (int j = 0; j < vertices; j++) {
            printf("%d ", adj_matrix[i][j]);
        }
        printf("\n");
    }
}

int main() {
    graph g;
    int choice, v1, v2;

    while (true) {
        printf("\nMENU:\n1. Insert Edge\n2. Delete Edge\n3. Search Edge\n4. Display Adjacency Matrix\n5. Exit\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice) {

        case 1:
            printf("Enter vertices (v1 v2) to insert edge: ");
            scanf("%d %d", &v1, &v2);
            if (g.insert(v1, v2)) {
                printf("Edge inserted successfully!\n");
            } else {
                printf("Insertion Failed!\n");
            }
            break;

        case 2:
            printf("Enter vertices (v1 v2) to delete edge: ");
            scanf("%d %d", &v1, &v2);
            if (g.remove(v1, v2)) {
                printf("Edge deleted successfully!\n");
            } else {
                printf("Deletion failed!\n");
            }
            break;

        case 3:
            printf("Enter vertices (v1 v2) to search edge: ");
            scanf("%d %d", &v1, &v2);
            if (g.search(v1, v2)) {
                printf("Edge found in the graph.\n");
            } else {
                printf("Edge not found in the graph.\n");
            }
            break;

        case 4:
            g.display();
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
