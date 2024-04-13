#include<stdio.h>
#include<stdlib.h>
#define SIZE 10

class array
{
	int arr[SIZE];
	int cur;
	public: array()
	{
		cur=-1;
	}
	int insert_beg(int);
	int insert_position(int, int);
	int insert_end(int);
	int delete_beg();
	int delete_position(int);
	int delete_end();
	int search(int);
	int display();
};

int main()
{
	array l1;
	int choice, num, pos, i;

	while(1)
	{
		printf("\nMENU \n1. Insert at Beginning \n2. Insert at Position \n3. Insert at End \n");
		printf("4. Delete at Beginning \n5. Delete at Position \n6. Delete at End \n");
		printf("7. Search an Element \n8. Display the Array \n9. Exit \n");
		printf("Enter your choice : ");
		scanf("%d", &choice);
		
		switch(choice)
		{
			case 1: 
				printf("Enter the element you want to insert: ");
				scanf("%d", &num);
				if(l1.insert_beg(num))
				{
					printf("\n%d inserted successfully!\n", num);
				}
				else
				{
					printf("\nInsertion failed!. array is full");
				}
				break;
			
			case 2:
				printf("\nEnter the element you want to insert: ");
				scanf("%d", &num);
				printf("\nEnter the position: ");
				scanf("%d", &pos);
				if(l1.insert_position(num, pos))
				{
					printf("\n%d inserted successfully!\n", num);
				}
				else
				{
					printf("\nInsertion failed!. array is full");
				}
				break;

			case 3:
				printf("\nEnter the element you want to insert: ");
				scanf("%d", &num);
				if(l1.insert_end(num))
				{
					printf("\n%d inserted successfully!\n", num);
				}
				else
				{
					printf("\nInsertion failed!. array is full");
				}
				break;

			case 4:
				l1.delete_beg();
				printf("\nThe first element was deleted!\n");
				break;

			case 5:
				printf("\nEnter the position you want to delete: ");
				scanf("%d", &pos);
				l1.delete_position(pos);
				printf("\nElement at position %d was successfully deleted\n", pos);
				break;

			case 6:
				l1.delete_end();
				printf("\nThe last element was deleted!\n");
				break;

			case 7:
				printf("\nEnter the element you want to search: ");
				scanf("%d", &num);
				l1.search(num);
				break;

			case 8:
				printf("\nThe array is: \n");
				l1.display();
				break;
			
			case 9:
				exit(0);
				break;
			
			default:
				printf("\nInvalid Choice!");
				break;
		}
	}
	return 0;
}

int array::insert_beg(int num)
{
    if(cur==SIZE-1)
    {
        return 0;
    }
    else if(cur==-1)
    {
        cur = 0;
        arr[0]=num;
        return 1;
    }
    else
    {
        for(int i=cur;i>=0;i--)
        {
            arr[i+1]=arr[i];
        }
        cur = cur + 1;
        arr[0]=num;
        return 1;

    }
}
int array::insert_end(int num)
{
    if(cur==SIZE-1)
    {
        return 0;
    }
    else
    {
        cur = cur + 1;
        arr[cur]=num;
        return 1;

    }
}
int array::insert_position(int num,int pos)
{
        arr[pos]=num;
        return 1;


}
int array::delete_beg()
{

       for(int i=0;i<=cur;i++)
        {
            arr[i]=arr[i+1];
        }
       arr[cur]=NULL;

        return 1;


}
int array::delete_end()
{
       printf("Popped %d\n",arr[cur]);

       arr[cur]=NULL;

}
int array::search(int num){
int a=0;
 for(int i=0;i<=cur;i++){
    if(arr[i]==num){
        printf("Found %d at %d\n",num,i);
        a=1;
    }
 }
 if(a==0){
    printf("Not Found\n");
 }
}
int array::delete_position(int pos)
{
    for(int i=pos;i<=cur;i++)
        {
            arr[i]=arr[i+1];
        }

        arr[cur]=NULL;
        return 1;

}

int array::display()
{
    printf("\nThe contents of the array are:");
    for(int i=0;i<=cur;i++)
    {
        if(arr[i]!=0)
		{
			printf("%d ",arr[i]);
		}
    }
    printf("\n");
}