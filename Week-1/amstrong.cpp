#include<stdio.h>
#include<math.h>
#include<stdlib.h>
int* count(int *num){
  int *count = (int *)malloc(sizeof(int)); //dynamic memory allocation
  int *temp = (int *)malloc(sizeof(int));
  *count=0;
  *temp = *num;     
  while(*temp!=0){
    (*count)++;
    *temp/=10; 
  }
  return count; //returning the number of digits in the given integer
}
int check(int *num, int *count){
  int *temp = (int *)malloc(sizeof(int));
  int *sum = (int *)malloc(sizeof(int));
  int *dig = (int *)malloc(sizeof(int));
  *temp = *num;
  *sum=0;
  while(*temp>0){
    *dig=*temp%10;
    *sum += floor(pow(*dig, *count));
    *temp/=10;
  }
  return (*sum==*num); //checking if the sum and original number are equal
}
int main(){
  int* number = (int *)malloc(sizeof(int));
  int* count1 = (int *)malloc(sizeof(int));
  printf("Enter a number ");
  scanf("%d", number);
  count1 = count(number);
  if(check(number, count1)==1){
    printf("\nThe number %d is an Amstrong number", *number);
  }
  else{
    printf("\nThe number %d is not an Amstrong number", *number);
  }
  free(number);
  free(count1); //freeing the dynamically alloted memory 
  return 0;
}