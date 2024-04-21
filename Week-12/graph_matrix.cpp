//Program to implement Graph ADT with Adjacency Matrix.
#include <stdio.h>
#include <stdlib.h>
#define MAX_VERTICES 5

//Header file to implement Queue ADT using linked lists
class queue {
private:
    struct node {
        struct node* prev;
        int data;
        struct node* next;
    };

    struct node* front;
    struct node* rear;

public:
    queue() {
        front = nullptr;
        rear = nullptr;
    }

    bool isempty();
    int enqueue(int);
    int dequeue();
    int peek();
};

//Method to check if the queue is empty
bool queue :: isempty() {
    return rear == nullptr;
}

//Method to insert an element into the queue. Time Complexity O(1)
int queue :: enqueue(int num) {
    struct node* newnode = (struct node*)malloc(sizeof(struct node));
    newnode->data = num;
    newnode->next = nullptr;

    if (isempty()) {
        front = rear = newnode;
    } else {
        rear->next = newnode;
        newnode->prev = rear;
        rear = newnode;
    }
    return 1;
}

//Method to delete an element from the queue. Time Complexity O(1)
int queue :: dequeue() {
    if (isempty()) {
        printf("Queue is empty!");
        return -1;
    } else {
        int del_val = front->data;
        front = front->next;
        return del_val;
    }
}

//Method to view the front element of the queue. Time Complexity O(1)
int queue :: peek() {
    if (isempty()) {
        printf("Queue is empty!");
        return -1;
    } else {
        return front->data;
    }
}

//Header file to implement stack ADT using linked list
class stack {
private:
    struct node {
        char data;
        struct node* next;
    };

    struct node* top;

public:
    stack() {
        top = nullptr;
    }

    bool isempty();
    char push(char);
    char pop();
    char peek();
    void display();
};

//Method to check if the stack is empty
bool stack :: isempty() {
    return top == nullptr;
}

//Method to insert element into the stack. Time Complexity O(1).
char stack :: push(char element) {
    struct node* newnode = (struct node*)malloc(sizeof(struct node));
    newnode->data = element;
    newnode->next = top;
    top = newnode;
    char j = '1';
    return j;
}

//Method to delete the topmost element of the stack. Time Complexity O(1).
char stack :: pop() {
    struct node* temp = top;
    if (isempty()) {
        printf("Stack Underflow\n");
        char j = '-';
        return j;
    } else {
        top = top->next;
        char del_val = temp->data;
        free(temp);
        return del_val;
    }
}

//Method to display the topmost element in stack. Time Complexity O(1).
char stack :: peek() {
    struct node* temp = top;
    char j;
    if (isempty()) {
        printf("Stack Empty\n");
        j = '-';
        return j;
    } else {
        return temp->data;
    }
}

//Method to display the stack. Time Complexity O(n).
void stack :: display() {
    struct node* temp = top;
    if (isempty()) {
        printf("\nStack empty!");
    } else {
        printf("\nStack elements are: ");
        while (temp != nullptr) {
            printf("%c ", temp->data);
            temp = temp->next;
        }
    }
}

//Graph Implementation
class graph {
private:
    int vertices;
    int adj_matrix[MAX_VERTICES][MAX_VERTICES];
    queue q;
    stack s;

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
    void breadth_first(int);
    void depth_first(int);
    void df_recursive(int, bool[]);
};

// Method to insert an edge into the graph. Time Complexity O(1).
bool graph::insert(int v1, int v2) {
    if (v1 - 1 < 0 || v1 - 1 >= vertices || v2 - 1 < 0 || v2 - 1 >= vertices) {
        printf("Invalid vertex indices!\n");
        return false;
    }
    adj_matrix[v1 - 1][v2 - 1] = 1;
    adj_matrix[v2 - 1][v1 - 1] = 1;
    return true;
}

// Method to search for an edge in the graph. Time Complexity O(1).
bool graph::search(int v1, int v2) {
    if (v1 - 1 < 0 || v1 - 1 >= vertices || v2 - 1 < 0 || v2 - 1 >= vertices) {
        printf("Invalid vertex indices!\n");
        return false;
    }
    return adj_matrix[v1 - 1][v2 - 1] == 1;
}

// Method to remove an edge from the graph. Time Complexity O(1).
bool graph::remove(int v1, int v2) {
    if (v1 - 1 < 0 || v1 - 1 >= vertices || v2 - 1 < 0 || v2 - 1 >= vertices) {
        printf("Invalid vertex indices!\n");
        return false;
    }
    adj_matrix[v1 - 1][v2 - 1] = 0;
    adj_matrix[v2 - 1][v1 - 1] = 0; 
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

// Method to perform Breadth First Traversal of the graph starting from a given vertex. Time Complexity O(n^2).
void graph::breadth_first(int startVertex) {
    bool visited[MAX_VERTICES] = {false};
    visited[startVertex - 1] = true;
    q.enqueue(startVertex);

    while (!q.isempty()) {
        int current = q.dequeue();
        printf("%d ", current);

        for (int i = 0; i < vertices; i++) {
            if (adj_matrix[current - 1][i] && !visited[i]) {
                visited[i] = true;
                q.enqueue(i + 1);
            }
        }
    }
    printf("\n");
}

// Method to perform Depth First Traversal of the graph starting from a given vertex. Time Complexity O(n^2).
void graph::depth_first(int startVertex) {
    bool visited[MAX_VERTICES] = {false};
    df_recursive(startVertex - 1, visited);
    printf("\n");
}

// Utility function for depth_first traversal.
void graph::df_recursive(int vertex, bool visited[]) {
    visited[vertex] = true;
    printf("%d ", vertex + 1);

    for (int i = 0; i < vertices; i++) {
        if (adj_matrix[vertex][i] && !visited[i]) {
            df_recursive(i, visited);
        }
    }
}

int main() {
    graph g;
    int choice, v1, v2;

    while (true) {
        printf("\nMENU:\n1. Insert Edge\n2. Delete Edge\n3. Search Edge\n4. Display Adjacency Matrix\n5. breadth_first\n6. depth_first\n7. Exit\nEnter your choice: ");
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
            printf("Enter starting vertex for breadth_first: ");
            scanf("%d", &v1);
            printf("breadth_first Traversal: ");
            g.breadth_first(v1);
            break;

        case 6:
            printf("Enter starting vertex for depth_first: ");
            scanf("%d", &v1);
            printf("depth_first Traversal: ");
            g.depth_first(v1);
            break;

        case 7:
            exit(0);

        default:
            printf("Invalid choice!\n");
            break;
        }
    }

    return 0;
}
