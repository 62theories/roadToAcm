#include <stdio.h>



int main()
{
	int m,n;
	int a,i,j;
	int amount;
	int count;
	scanf(" %d",&m); 
	scanf(" %d",&n);
	int arr[m][n];
	
	for(i=0;i<m;i++)
	{
		for(j=0;j<n;j++)
		{
			scanf(" %d",&arr[i][j]);
		}
	}
	
	scanf(" %d",&amount);
	
	int whatToFind[amount];
	
	for(i=0;i<amount;i++)
	{
		scanf(" %d",&whatToFind[i]);
	}
	
	for(a=0;a<amount;a++)
	{
		count = 0;
		printf("%d\n",whatToFind[a]);
		for(i=0;i<m;i++)
		{
			for(j=0;j<n;j++)
			{
				if(arr[i][j] == whatToFind[a])
				{
					printf("%d %d ",i,j);
					count++;	
				}	
			}	
		}
		if(count != 0)
		{
			printf("\n");
		}
		printf("%d\n",count);
	}
	
	return 0;
}
