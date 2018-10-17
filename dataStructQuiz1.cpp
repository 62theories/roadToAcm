#include <bits/stdc++.h>

using namespace std;

int arr[10][10];
bool isEmpty[10];
int index[10];
int size[10];
int main()
{
	
	for(int i=0;i<10;i++)
	{
		for(int j=0;j<10;j++)
		{
			arr[i][j] = 0;
		}
	}
	
	for(int i=0;i<10;i++)
	{
		size[i]=0;
	}
	
	for(int i=0;i<10;i++)
	{
		index[i] = 0;
	}
	
	for(int i=0;i<10;i++)
	{
		isEmpty[i] = false;
	}
	
	int number;
	int input;
	
	
	cin >> number;
	
	
	for(int i =0;i<number;i++)
	{
		cin >> input;
		arr[input%10][index[input%10]%10] = input;
		index[input%10] = (index[input%10] + 1)%10;
		if(isEmpty[input%10] == false)
		{
			isEmpty[input%10] = true;
		 } 
		 if(size[input%10]<10)
		 {
		 	size[input%10]++;
		 }
	}
	
	for(int i =0;i<10;i++)
	{
		if(isEmpty[i] == false)
		{
			cout << "-" << endl;
		 } 
		 
		 else
		 {
		 	for(int j=0;j<size[i];j++)
		 	{
		 		cout << arr[i][j] << " ";
			 }
			 cout << endl;
		 }
	}
	
	return 0;
}
