#include <stdio.h>
#include <stdlib.h>
struct Node{
	struct Node *next;
	int data;
};

typedef struct Node node;

node* findPreNode(node *Head,int number);
node* I(node *Head,int at,int number);
node* A(node *Head,int number);
node* D(node *Head,int number);
void P(node *Head);
int main()
{
	node *Head = NULL;
	char c;
	int n;
	int n2;
	while(1)
	{
		scanf(" %c",&c);
		if(c == '0')
		{
			return 0;
		}
		else if(c == 'P')
		{
			P(Head);	
		}
		else
		{
			scanf(" %d",&n);
		
			if(c == 'A')
			{
				Head = A(Head,n);
			}
			else if(c == 'D')
			{
				Head = D(Head,n);
			}
			else if(c == 'I')
			{
				scanf(" %d",&n2);
				Head = I(Head,n,n2);
			}
		}
	}
	return 0;
	
}

node* findPreNode(node *Head,int number)
{
	node *temp = Head;
	if(temp->next == NULL)
	{
		return NULL;
	}
	while(temp->next->data != number)
	{
		if(temp->next == NULL)
		{
			return NULL;
		}
		temp = temp->next;
	}
	return temp;
}

node* A(node *Head,int number)
{
	node *temp;
	if(Head == NULL)
	{
		Head = (node*)malloc(sizeof(node));
		Head->data = number;
		Head->next = NULL;
		if(Head == NULL)
		{
			printf("Head is still NULL\n");
		}
	}
	else
	{
		temp = Head;
		while(temp->next!=NULL)
		{
			temp = temp->next;
		}
		temp->next = (node*)malloc(sizeof(node));
		temp->next->data = number;
		temp->next->next = NULL;
	}
	return Head;
}

node* D(node *Head,int number)
{
	node *temp = Head;
	if(Head->data == number)
	{
		Head = Head->next;
		return Head;
	}
	node *preNode = findPreNode(Head,number);
	if(preNode == NULL)
	{
		return Head;
	}
	else
	{
		if(preNode->next->next == NULL)
		{
			preNode->next = NULL;
		}
		else
		{
			preNode->next = preNode->next->next;
		}
	}
	return Head;
}

void P(node *Head)
{
	node *temp;
	if(Head == NULL)
	{
		printf("Head is NULL");
		return;
	}
	temp = Head;
	while(temp != NULL)
	{
		printf("%d ",temp->data);
		temp = temp->next;
	}
	printf("\n");
}

node* I(node *Head,int at,int number)
{
//	node *preNode = findPreNode(Head,at);
//	if(preNode == NULL)
//	{
//		return Head;
//	}
//	else
//	{
//		if(preNode->next->next == NULL)
//		{
//			preNode->next->next = (node*)malloc(sizeof(node));
//			preNode->next->next->data = number;
//			preNode->next->next->next = NULL;
//		}
//		else
//		{
//			node* temp = (node*)malloc(sizeof(node));
//			temp->data = number;
//			temp->next = preNode->next->next;
//			preNode->next->next = temp;
//		}
//	}
	int count = 1;
	node* temp = Head;
	node* temp2;
	if(Head == NULL)
	{
		return Head;
	}
	else
	{
		while(count != at)
		{
			if(temp->next == NULL)
			{
				return Head;
			}
			else
			{
				temp = temp->next;
				count++;
			}
		}
		if(temp->next == NULL)
		{
			Head = A(Head,number);
		}
		else
		{
			temp2 = (node*)malloc(sizeof(node));
			temp2->next = temp->next;
			temp2->data = number;
			temp->next = temp2;
		}
	}
	return Head;
}
