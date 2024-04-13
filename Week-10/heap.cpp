//Program to implement Priority Queue using Heap Data Structure
#include <stdio.h>
#include <stdlib.h>
#define SIZE 10

class heap{
    private:
        int max_heap[SIZE];
        int current;
        
    public:
        heap(){
            current=-1;
        }
        int get_current();
        int insert(int);
        int remove();
        int heap_sort();
        int search(int);
        void display();
        int swap(int *, int*);
        int heapify_up(int);
        int heapify_down(int);
};

//Method to get the current size of the heap. Time Complexity O(1).
int heap ::  get_current(){
    return current;
}

//Method to swap two elements. Time Complexity O(1).
int heap::swap(int *x, int *y){
    int temp=*x;
    *x=*y;
    *y=temp;
}

//Method to insert an element into the heap. Time Complexity O(log n).
int heap :: insert(int data){
    if(current==SIZE-1){
        printf("Heap is full!");
        return 0;
    }
    current++;
    max_heap[current]=data;
    heapify_up(current);
    return 1;    
}

//Method to heapify for insertion. Time Complexity O(log n).
int heap :: heapify_up(int pos){
    int parent= (pos-1)/2;
    while(pos>0 && max_heap[parent]<max_heap[pos]){
        swap(&max_heap[parent], &max_heap[pos]);
        pos=parent;
        parent=(pos-1)/2;
    }
}

//Method to delete an element from the heap. Time Complexity O(log n).
int heap :: remove(){
    if (current < 0) {
        printf("Heap is empty!\n");
        return 0;
    }
    int del_val = max_heap[0];
    max_heap[0] = max_heap[current];
    current--;
    heapify_down(0);
    return del_val;
}

//Method to heapify for deletion. Time Complexity O(log n).
int heap :: heapify_down(int parent){
    int left=2*parent + 1;
    int right = 2*parent + 2;
    int largest=parent;
    
    if(left<current && max_heap[left]>max_heap[largest]){
        largest=left;
    }
    if(right<current && max_heap[right]>max_heap[largest]){
        largest=right;
    }

    if(largest!=parent){
        swap(&max_heap[largest], &max_heap[parent]);
        heapify_down(largest);
    }
}

//Method to search for an element in heap. Time Complexity O(n).
int  heap :: search(int ele){
    if(current==-1){
        printf("Heap is empty!\n");
        return 0;
    }
    for (int i = 0; i <= current; i++) {
        if (ele == max_heap[i]) {
            return (i+1);
        }
    }
    return 0;
}

//Method to display the elements in heap. Time Complexity O(n).
void heap :: display(){
    if(current==-1){
        printf("Heap is empty. No elements to display!");
    }
    else{
        printf("\nThe elements of the heap are: ");
        for(int i=0; i<=current; i++){
            printf("%d ", max_heap[i]);
        }
    }
}

//Method to sort the array in descending order. Time Complexity O(nlog n).
int heap :: heap_sort() {
    if(current==-1){
        printf("Heap is empty!\n");
        return 0;
    }
    int index=0;
    printf("Heap is descending order: ");
    while(current>=0){
        printf("%d ", remove());
    }
    return 1;
}


int main(){
    heap h;
    int i, choice, data;
    int result, cur;
    
    while(1){
        printf("\nMENU: \n1. Insert\n2. Delete\n3. Search\n4. Heap Sort\n5. Display\n6. Exit\nEnter your choice: ");
        scanf("%d", &choice);

        switch(choice){
            case 1:
                printf("Enter the element to be inserted: ");
                scanf("%d", &data);
                if(h.insert(data)){
                    printf("Insertion Successfull!");
                }
                else{
                    printf("Insertion Failed!");
                }
                break;
            
            case 2:
                if(h.remove()){
                    printf("Deletion Successfull!");
                }
                else{
                    printf("Deletion Failed!");
                }
                break;
            
            case 3: 
                printf("Enter the element to be searched: ");
                scanf("%d", &data);
                result=h.search(data);
                if(result){
                    printf("Element %d found at position %d", data, result);
                }
                else{
                    printf("Element %d not found!", data);
                }
                break;
            
            case 4:
                int arr[SIZE];
                result=h.heap_sort();
                if(!result){
                    printf("Sorting cannot be done!");
                }
                break;
            
            case 5:
                h.display();
                break;

            case 6:
                exit(1);
                break;

            default:
                printf("Invalid Choice!");
                break;
        }
    }
}