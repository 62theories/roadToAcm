#include <stdio.h>
#include <stdlib.h>


struct Data{
	int column[10];
	int size;
	int indexNow;
	int isEmpty; 
};

typedef struct Data data; 

data *arr;
int i,j;
int main()
{
	arr = (data*)malloc(sizeof(data)*10);
	for(i=0;i<10;i++)
	{
		for(j=0;j<10;j++)
		{
			arr[i].column[j] = 0;	
		}
		arr[i].size = 0;
		arr[i].indexNow = 0;
		arr[i].isEmpty = 0;	
	}
	int number;
	int input;
	
	scanf(" %d",&number);
	
	for(i =0;i<number;i++)
	{
		scanf(" %d",&input);
		arr[input%10].column[arr[input%10].indexNow] = input;
		arr[input%10].indexNow = (arr[input%10].indexNow + 1)%10; 
		if(arr[input%10].isEmpty == 0)
		{
			arr[input%10].isEmpty = 1;
		 } 
		 if(arr[input%10].size<10)
		 {
		 	arr[input%10].size++;
		 }
	}
	
	for(i =0;i<10;i++)
	{
		if(arr[i].isEmpty == 0)
		{
			printf("-\n");
		 } 
		 
		 else
		 {
		 	for(j=0;j<arr[i].size;j++)
		 	{
		 		printf("%d ",arr[i].column[j]);
			 }
			 printf("\n");
		 }
	}
	
	return 0;
}
