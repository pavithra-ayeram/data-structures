#include <stdio.h>
#include "calculator.h" //including custom header file

int main()
{
    int choice;
    float num1 = 0, num2 =0;
    printf("Enter first number: ");
    scanf("%f", &num1);
    printf("Enter second number: ");
    scanf("%f", &num2);

    do 
    {
        printf("\nMenu:\n1. Add\n2. Subtract\n3. Multiply\n4. Divide\n5. Exit\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {

            case 1:
                printf("%f + %f = %f\n", num1, num2, sum(num1, num2));
                break;

            case 2:
                printf("%f - %f = %f\n", num1, num2, difference(num1, num2));
                break;

            case 3:
                printf("%f * %f = %f\n", num1, num2, product(num1, num2));
                break;

            case 4:
                if (num2 == 0)
                {
                    printf("Division by zero is not possible.\n");//checking for invalid input
                }
                else
                {
                    printf("%f / %f = %f\n", num1, num2, quotient(num1, num2));
                }
                break;

            case 5:
                break;

            default:
                printf("Invalid choice.\n");
                break;
        }
    } while (choice != 5); //exit condition

    return 0;
}
