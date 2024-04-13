//Program to check if the given string is balanced or not
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "balance.h"

int main(){
    stack s;
    char element[20];
    printf("\nEnter the string: ");
    scanf("%s",element);

    int n=strlen(element);
    for (int i=0; i<n; i++){
        if(element[i]=='('){
            s.push('(');
        }
        else if(element[i]==')'){
            if(s.isempty()){
                printf("Stack Underflow!");
            }
            else{
                s.pop();
            }
        }
    }
    if(s.isempty()){
        printf("String is Balanced!");
    }
    else{
        printf("String Unbalanced!");
    }

}