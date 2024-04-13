#include<stdio.h>

int search(int *arr, int n, int target){
	int flag=-1, i=0;	
	for(i=0;i<n;i++){
		if(arr[i]==target){
			flag=i;
			break;
			}
		}
	return flag;
	}
		
int main(){
	int num=0, i=0;
	int position=0;
	printf("Enter the number of elements in the array: ");
	scanf("%d", &num);
	
	int n[num];
	for(i=0;i<num;i++){
	printf("Enter element %d ", i+1);
	scanf("%d", &n[i]);
	}
	
	int target=0;
	printf("Enter the target number ");
	scanf("%d",&target);
	
	position=search(n, num, target);
	
	if(position!=-1){	
		printf("The target is found at the position %d", position+1);
		}
	else{
		printf("The target is not found");
		}
	return 0;
	}
		
