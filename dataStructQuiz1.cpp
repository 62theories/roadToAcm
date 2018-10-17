#include <bits/stdc++.h>

using namespace std;

struct Data{
	int column[10];
	int size;
	int indexNow;
	bool isEmpty; 
};

typedef Data data; 

data *arr;

int main()
{
	arr = (data*)malloc(sizeof(data)*10);
	for(int i=0;i<10;i++)
	{
		for(int j=0;j<10;j++)
		{
			arr[i].column[j] = 0;	
		}
		arr[i].size = 0;
		arr[i].indexNow = 0;
		arr[i].isEmpty = false;	
	}
	int number;
	int input;
	
	cin >> number;
	
	for(int i =0;i<number;i++)
	{
		cin >> input;
		arr[input%10].column[arr[input%10].indexNow] = input;
		arr[input%10].indexNow = (arr[input%10].indexNow + 1)%10; 
		if(arr[input%10].isEmpty == false)
		{
			arr[input%10].isEmpty = true;
		 } 
		 if(arr[input%10].size<10)
		 {
		 	arr[input%10].size++;
		 }
	}
	
	for(int i =0;i<10;i++)
	{
		if(arr[i].isEmpty == false)
		{
			cout << "-" << endl;
		 } 
		 
		 else
		 {
		 	for(int j=0;j<arr[i].size;j++)
		 	{
		 		cout << arr[i].column[j]<< " ";
			 }
			 cout << endl;
		 }
	}
	
	return 0;
}
