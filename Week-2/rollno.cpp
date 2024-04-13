#include <stdio.h>

int search(int *arr, int size, int target) {
    int start = 0;
    int end = size - 1;

    while (start <= end) {
        int mid = start + (end - start) / 2;

        if (arr[mid] == target) {
            return mid;  // Return the index if the roll number is found
        } else if (arr[mid] < target) {
            start = mid + 1;  // Roll number is in the right half
        } else {
            end = mid - 1;  // Roll number is in the left half
        }
    }

    return -1;  // Roll number not found in the array
}

int main() {
    int num;

    do {
        printf("Enter the number of students (positive integer): ");
        scanf("%d", &num);
    } while (num <= 0);

    int roll[num];

    for (int i = 0; i < num; i++) {
        printf("Enter roll number for student %d: ", i + 1);
        scanf("%d", &roll[i]);
    }


    int target;
    printf("\nEnter the roll number to search: ");
    scanf("%d", &target);

    int result = search(roll, num, target);

    if (result != -1) {
        printf("Roll number %d is present at index %d\n", target, result+1);
    } else {
        printf("Roll number %d is not present in the array\n", target);
    }

    return 0;
}

