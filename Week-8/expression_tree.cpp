//Program to implement the construction of expression tree using binary tree
#include <stdio.h>
#include <stdlib.h>
#include "expression_tree.h"

int main(){
    tree t;
    int choice;
    char postfix_exp[20];

    while(1){
        printf("\nMENU\n1. Enter postfix expression\n2. Construct Tree\n3. Prefix Expression\n4. Infix Expression\n5. Postfix Expression\n6. Exit\nEnter your choice: ");
        scanf("%d", &choice);
        printf("\n");

        switch(choice){
            case 1:
                printf("Enter postfix expression: ");
                scanf(" %s", postfix_exp);
                if (!t.isvalid(postfix_exp)) {
                    printf("Invalid postfix expression!\n");
                    postfix_exp[0] = '\0';  // Reset expression
                }
                break;

            case 2:
                if(postfix_exp[0] == '\0'){
                    printf("No expression available!");
                }
                else{
                    t.root = t.construct_tree(postfix_exp);
                    printf("Expression Tree Constructed Successfully\n");
                }
                break;

            case 3:
                if(t.get_root()==nullptr){
                    printf("No expression available!");
                }
                else{
                    printf("The prefix expression is: ");
                    t.preorder(t.get_root());
                    printf("\n");
                }
                break;

            case 4:
                if(t.get_root()==nullptr){
                    printf("No expression available!");
                }
                else{
                    printf("The infix expression is: ");
                    t.inorder(t.get_root());
                    printf("\n");
                }
                break;

            case 5:
                if(t.get_root()==nullptr){
                    printf("No expression available!");
                }
                else{
                    printf("The postfix expression is: ");
                    t.postorder(t.get_root());
                    printf("\n");
                }
                break;

            case 6:
                exit(0);
                break;

            default:
                printf("Invalid Choice!");
                break;
        }
    }
    return 0;
}
