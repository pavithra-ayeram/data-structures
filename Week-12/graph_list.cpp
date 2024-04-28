#include <stdio.h>
#include <stdlib.h>
#define MAX_VERTICES 5

class graph {
private:
    struct node {
    public:
        int vertex;
        node* next;
    };
    int vertices;
    node* adj_list[MAX_VERTICES];

public:
    graph() {
        vertices = MAX_VERTICES;
        for (int i = 0; i < vertices; i++) {
            adj_list[i] = nullptr;
        }
    }

    bool insert(int, int);
    bool search(int, int);
    bool remove(int, int);
    void display();
};

bool graph::insert(int v1, int v2) {
    if (v1 < 1 || v1 > vertices || v2 < 1 || v2 > vertices) {
        printf("Invalid vertex indices!\n");
        return false;
    }

    node* newNode1 = new node();
    newNode1->vertex = v2;
    newNode1->next = adj_list[v1 - 1];
    adj_list[v1 - 1] = newNode1;

    node* newNode2 = new node();
    newNode2->vertex = v1;
    newNode2->next = adj_list[v2 - 1];
    adj_list[v2 - 1] = newNode2;

    return true;
}

bool graph::search(int v1, int v2) {
    if (v1 < 1 || v1 > vertices || v2 < 1 || v2 > vertices) {
        printf("Invalid vertex indices!\n");
        return false;
    }

    node* temp = adj_list[v1 - 1];
    while (temp != nullptr) {
        if (temp->vertex == v2)
            return true;
        temp = temp->next;
    }

    return false;
}

bool graph::remove(int v1, int v2) {
    if (v1 < 1 || v1 > vertices || v2 < 1 || v2 > vertices) {
        printf("Invalid vertex indices!\n");
        return false;
    }

    node* current = adj_list[v1 - 1];
    node* prev = nullptr;

    // Search for the edge and keep track of the previous node
    while (current != nullptr && current->vertex != v2) {
        prev = current;
        current = current->next;
    }

    // If edge not found
    if (current == nullptr) {
        printf("Edge not found!\n");
        return false;
    }

    // If the edge is found, remove it
    if (prev == nullptr)
        adj_list[v1 - 1] = current->next;
    else
        prev->next = current->next;

    delete current;

    // Remove the reverse edge
    current = adj_list[v2 - 1];
    prev = nullptr;
    while (current != nullptr && current->vertex != v1) {
        prev = current;
        current = current->next;
    }
    if (prev == nullptr)
        adj_list[v2 - 1] = current->next;
    else
        prev->next = current->next;

    delete current;

    return true;
}

void graph::display() {
    printf("Adjacency List:\n");
    for (int i = 0; i < vertices; i++) {
        printf("%d -> ", i + 1);
        node* temp = adj_list[i];
        while (temp != nullptr) {
            printf("%d -> ", temp->vertex);
            temp = temp->next;
        }
        printf("NULL\n");
    }
}


int main() {
    graph g;
    int choice, v1, v2;

    while (true) {
        printf("\nMENU:\n1. Insert Edge\n2. Delete Edge\n3. Search Edge\n4. Display Adjacency List\n5. Exit\nEnter your choice: ");
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
