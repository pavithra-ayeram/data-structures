//Program to process the given string according to the given conditions and display the result
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "plus_removal.h"

int main(){
	stack s;
	queue q;
	char element;
	char input[100];
	int count;
	char prev='\0';

	printf("Enter the string: ");
	scanf("%100s", input);
	int n=strlen(input);

	for (int i=0; i<n; i++){
		q.enqueue(input[i]);
	}
	
	while(!q.isempty()){
		s.push(q.dequeue());
	}

	while(!s.isempty()){
		//Deleting the '+' symbol
		if(s.peek()=='+'){
			count++;
			prev=s.pop();
		}
		//Enqueueing the non-'+' characters
		else if(count==0 && s.peek()!='+'){
			prev=s.pop();
			q.enqueue(prev);
		}
		//Deleting the non-'+' characters with immediate '+' symbol to its right
		else{
			do{
				if(prev=='+'){
					s.pop();
				}
				count--;
			} while(count>0);
			count=0;
		}
	}

	printf("Output: ");
	while(!q.isempty()){
		s.push(q.dequeue());
	}

	while(!s.isempty()){
		printf("%c", s.pop());
	}
	return 0;
}
