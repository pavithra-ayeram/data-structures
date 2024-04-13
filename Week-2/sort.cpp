#include<stdio.h>

//sort the array in ascending order using bubble sort
int *ascendsort(int *n, int num){
	int i=0, j=0;
	int temp=0;
	for(j=0;j<num;j++){
		for (i=0;i<num-1;i++){
			if(n[i+1]<n[i]){
				temp=n[i+1];
				n[i+1]=n[i];
				n[i]=temp;
				}
			}
		}
	return n;
	}	
		
//sort the array in descending order using bubble sort		
int *descendsort(int *n, int num){
	int i=0, j=0;
	int temp=0;
	for(j=0;j<num;j++){
		for (i=0;i<num-1;i++){
			if(n[i+1]>n[i]){
				temp=n[i+1];
				n[i+1]=n[i];
				n[i]=temp;
				}
			}
		}
	return n;
	}	
		
int main(){

	int num;
	printf("Enter the number of elements in the array: ");
	scanf("%d", &num);

	//getting the input	
	int n[num];
	int i=0;
	for (i=0;i<num;i++){
		printf("Enter element %d ",i+1);
		scanf("%d",&n[i]);
		}
	
	//asking for choice
	int ch=0;
	do{
	
	printf("\nMENU\n1.Ascending Order\n2. Descending Order\n3. Exit");
	printf("\nEnter your choice: ");
	scanf("%d", &ch);
	
	//performing the required block of code
	switch(ch){
	
		case 1:
			ascendsort(n, num);
			printf("The array after sorting is: ");
			for(i=0;i<num;i++){
				printf("%d ", n[i]);
				}
			break;
		
		case 2:
			descendsort(n, num);
			printf("The array after sorting is: ");
			for(i=0;i<num;i++){
				printf("%d ", n[i]);
				}
			break;
		
		case 3:
			break;
		
		default:
			printf("Enter a valid choice");
			break;
		}
	}while(ch!=3);
	
	return 0;
	}
