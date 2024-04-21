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
    void breadth_first(int);
    void depth_first(int);
    void df_recursive(int, bool[]);
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

void graph::breadth_first(int startVertex) {
    bool* visited = new bool[vertices]();
    queue q; // Using your queue implementation

    visited[startVertex - 1] = true;
    q.enqueue(startVertex);

    while (!q.isempty()) {
        int current = q.dequeue();
        printf("%d ", current);

        node* temp = adj_list[current - 1];
        while (temp != nullptr) {
            if (!visited[temp->vertex - 1]) {
                visited[temp->vertex - 1] = true;
                q.enqueue(temp->vertex);
            }
            temp = temp->next;
        }
    }

    delete[] visited;
    printf("\n");
}

void graph::df_recursive(int vertex, bool visited[]) {
    visited[vertex - 1] = true;
    printf("%d ", vertex);

    node* temp = adj_list[vertex - 1];
    while (temp != nullptr) {
        if (!visited[temp->vertex - 1]) {
            df_recursive(temp->vertex, visited);
        }
        temp = temp->next;
    }
}

void graph::depth_first(int startVertex) {
    bool* visited = new bool[vertices]();
    df_recursive(startVertex, visited);
    printf("\n");
    delete[] visited;
}

int main() {
    graph g;
    int choice, v1, v2;

    while (true) {
        printf("\nMENU:\n1. Insert Edge\n2. Delete Edge\n3. Search Edge\n4. Display Adjacency List\n5. breadth_first Traversal\n6. depth_first Traversal\n7. Exit\nEnter your choice: ");
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
            printf("Enter starting vertex for breadth_first Traversal: ");
            scanf("%d", &v1);
            printf("breadth_first Traversal: ");
            g.breadth_first(v1);
            break;

        case 6:
            printf("Enter starting vertex for depth_first Traversal: ");
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
