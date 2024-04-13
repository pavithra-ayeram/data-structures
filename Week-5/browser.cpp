//Program to implement browser's front and back functionality using doubly linked lists
#include <stdio.h>
#include <stdlib.h>
#include "webpage.h" //Custom header file

int main() {
    web_page browser;
    int choice, result;

    while (true) {
        printf("\nMENU\n\t1. New Webpage\n\t2. Front\n\t3. Back\n\t4. Exit\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                result=browser.new_page();
                if(result){
					printf("New webpage %d added!", result);
				}
                else{
					printf("Insertion failed!");
				}
                break;

            case 2:
                browser.front();
                break;

            case 3:
                browser.back();
                break;

            case 4:
                exit(0);

            default:
                printf("\nInvalid Choice!");
        }

        printf("\nCurrent webpage list is: ");
        browser.display();
    }

    return 0;
}